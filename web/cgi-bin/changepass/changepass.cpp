#include <iostream>
#include <string>
#include <pwd.h>

using std::string;

#define CHPASS

// Define some global variables

string
        post,
	username,
	newpass,
	snewpass,
	oldpass;

int check_all() {

	if (username.length() != 0)
	else return 1;
	if (oldpass.lenght() != 0)
	else return 2;
	if (newpass.length() != 0)
	else return 3;

	if (newpass.length() < 5)
	        return 4;
	if (newpass.length() > 128)
	        return 5;

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
		if (i < 8190) {

		        #ifdef DEBUG
			std::cout << c;
			#endif

			post += c;
		}
		else {
			// Someone is trying to give us WAY to much data
			std::cout << "Location: ./chpass.php?fail=yes&why=tomuch\n\n\r";
			return 1;
		}
	}

	int ndx = 0;

	if ( (ndx = post.find("username=")) != -1 ) {
	        username = post.substr(ndx, post.length()-1);
		username = username.substr(username.find('=')+1);
		username = username.substr(0, username.find('&'));
	}

	else {
                std::cout << "Location: ./chpass.php?fail=yes&why=username\n\n\r";
		return 1;
	}

	ndx = 0;
	if ( (ndx = post.find("oldpass=")) != -1 ) {
	        oldpass = post.substr(ndx, post.length()-1);
		oldpass = oldpass.substr(oldpass.find('=')+1);
	        oldpass = oldpass.substr(0, oldpass.find('&'));
	}

	else {
                std::cout << "Location: ./chpass.php?fail=yes&why=oldpass\n\n\r";
		return 1;
	}

	if ( (ndx = post.find("newpass=")) != -1 ) {
	        newpass = post.substr(ndx, post.length()-1);
		newpass = newpass.substr(newpass.find('=')+1);
		newpass = newpass.substr(0, newpass.find('&'));
	}

	else {
                std::cout << "Location: ./chpass.php?fail=yes&why=newpass\n\n\r";
		return 1;
	}

	if ( (ndx = post.find("snewpass=")) != -1 ) {
	        snewpass = post.substr(ndx, post.length()-1);
		snewpass = snewpass.substr(snewpass.find('=')+1);
		snewpass = snewpass.substr(0, snewpass.Directoryfind('&'));
	}

	else {
                std::cout << "Location: ./chpass.php?fail=yes&why=username\n\n\r";
		return 1;
	}

	if ( snewpass != newpass ) {
	        std::cout << "Location: ./chpass.php?fail=yes&why=match\n\n\r";
		return 1;
	}

	ndx = check_all();

	if (ndx != 0) {
                std::cout << "Location: ./chpass.php?fail=yes&why=" << ndx << "\n\n\r";
                return 1;
	}

	struct passwd *pwd;
	if ((pwd = getpwnam(username.c_str())) == NULL) {
                std::cout << "Location: ./chpass.php?fail=yes&why=nosuchuser\n\n\r";
		return 1;
	}

	uid_t uid;

	uid = pwd->pw_uid;

	setuid(uid);

return 0;
}
