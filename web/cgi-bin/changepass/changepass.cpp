#include <iostream>
#include <string>

#include <pwd.h>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
// #include <pw_scan.h>

using std::string;

// Define some global variables

string
        post,
	username,
	newpass,
	snewpass,
	oldpass;

const string lower ("abcdefghijklmnopqrstvwxyz");
const string upper ("ABCDEFGHIJKLMNOPQRSTVWXYZ");
const string letters = lower + upper + '_';
const string digits ("1234567890");
const string rndchars ("\\/#$@!^*~-+");
const string allowed = letters + digits + rndchars;
static char const chars[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.";

string pw_pwcrypt(char *password)
{
	int             i;
	char            salt[12];

	static char     buf[256];

	/*
	 * Calculate a salt value
	 */
	for (i = 0; i < 8; i++)
		salt[i] = chars[arc4random() % 63];
	salt[i] = '\0';

	return crypt(password, salt);
}

int check_password() {

        if(newpass.find_first_not_of(allowed, 1) == -1 && snewpass.find_first_not_of(allowed)) {
                return 0;
	}
	else {
                return 1;
	}
}

int check_all() {

	if (username.length() != 0) { }
	else { return 1; }
	if (oldpass.length() != 0) { }
	else { return 2; }
	if (newpass.length() != 0) { }
	else { return 3; }

	if (newpass.length() < 5)
	        return 4;
	if (newpass.length() > 128)
	        return 5;

return 0;

}

int get_all () {
	int ndx = 0;

	if ( (ndx = post.find("username=")) != -1 ) {
	        username = post.substr(ndx, post.length()-1);
		username = username.substr(username.find('=')+1);
		username = username.substr(0, username.find('&'));
		#ifdef DEBUG
		        std::cout << "Username: \t" << username << "\n";
		#endif
	}

	else {
                std::cout << "Location: ./chpass.php?fail=yes&why=username\n\n\r";
		return 1;
	}

	if ( (ndx = post.find("oldpass=")) != -1 ) {
	        oldpass = post.substr(ndx, post.length()-1);
		oldpass = oldpass.substr(oldpass.find('=')+1);
	        oldpass = oldpass.substr(0, oldpass.find('&'));
		#ifdef DEBUG
		        std::cout << "Oldpass: \t" << oldpass << "\n";
		#endif
	}

	else {
                std::cout << "Location: ./chpass.php?fail=yes&why=oldpass\n\n\r";
		return 1;
	}

	if ( (ndx = post.find("newpass=")) != -1 ) {
	        newpass = post.substr(ndx, post.length()-1);
		newpass = newpass.substr(newpass.find('=')+1);
		newpass = newpass.substr(0, newpass.find('&'));
		#ifdef DEBUG
		        std::cout << "Newpass: \t" << newpass << "\n";
		#endif
	}

	else {
                std::cout << "Location: ./chpass.php?fail=yes&why=newpass\n\n\r";
		return 1;
	}

	if ( (ndx = post.find("snewpass=")) != -1 ) {
	        snewpass = post.substr(ndx, post.length()-1);
		snewpass = snewpass.substr(snewpass.find('=')+1);
		snewpass = snewpass.substr(0, snewpass.find('&'));
		#ifdef DEBUG
		        std::cout << "Snewpass: \t" << snewpass << "\n";
		#endif
	}

	else {
                std::cout << "Location: ./chpass.php?fail=yes&why=snewpass\n\n\r";
		return 1;
	}

	if ( snewpass != newpass ) {
	        std::cout << "Location: ./chpass.php?fail=yes&why=match\n\n\r";
		return 1;
	}
return 0;
}

int main() {
        #ifdef DEBUG
	std::cout << "Content-type: text/html\n\n\r";
	#endif

	// Define variables for the next while loop
	char c;
	int i = 0;

	while ( (c = getchar()) != EOF )
	{
                post += c;
	}

        int ndz = get_all();
	if (ndz != 0) {
                return ndz;
	}

	int ndx = check_all();

	if (ndx != 0) {
                std::cout << "Location: ./chpass.php?fail=yes&why=" << ndx << "\n\n\r";
                return 1;
	}

	struct passwd *pw;

        // Check if the user exists
	if ((pw = getpwnam(username.c_str())) == NULL) {
                std::cout << "Location: ./chpass.php?fail=yes&why=nosuchuser\n\n\r";
		return 1;
	}

	// Check if the password provided is the correct one

	if (strcmp( crypt(oldpass.c_str() ,pw->pw_passwd), pw->pw_passwd)) {
	        std::cout << "Location: ./chpass.php?fail=yes&why=oldpass_incorrect\n\n\r";
		return 1;
	}

	// Check the password, to make sure it only contains valid characters.

	if (check_password()) {
	        std::cout << "Location: ./chpass.php?fail=yes&why=newpass_invalid_char\n\n\r";
		return 1;
	}

return 0;
}
