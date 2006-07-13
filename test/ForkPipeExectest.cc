#include <iostream>
#include <string>
#include <vector>
#include <0x58-unix/Exec.h>

int main() {

        std::vector<std::string> blah;
        
        blah.push_back(std::string("/usr/bin/find"));
        blah.push_back(std::string("."));
        
        x58unix::Exec *MyExec = new x58unix::Exec(blah);
        MyExec->doExec();
                
        std::string mystring;
        
        while (MyExec->read(mystring) > 0)
                std::cout << mystring << std::endl;
	
	delete MyExec;        

return 0;
}
