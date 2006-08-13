#include <iostream>
#include <string>
#include <vector>
#include <0x58-unix/Fork.h>
#include <0x58-unix/Pipe.h>
#include <0x58-unix/Exec.h>

int main() {

        std::vector<std::string> blah;
        
        blah.push_back(std::string("/usr/bin/find"));
        blah.push_back(std::string("."));

#ifdef TESTING       
        x58unix::Pipe::pair_pipes * pipes = new x58unix::Pipe::pair_pipes();
        
        x58unix::Exec *MyExec = new x58unix::Exec(new x58unix::Pipe(new x58unix::Fork(), pipes), blah);

        MyExec->execute();
                
        std::string mystring;
        
        while ( std::getline(pipes->first, mystring) ) {
                std::cout << mystring << std::endl;
        }
        
        std::cout << std::flush;
        
        delete MyExec;
        
        MyExec = new x58unix::Exec(new x58unix::Fork(), blah);
	
	MyExec->execute();
	
	delete MyExec;
	
	sleep(5);
#endif        
        x58unix::Exec *MyExec = new x58unix::Exec(new x58unix::Noop(x58unix::Noop::Child), blah);
	
	MyExec->execute();
	
	delete MyExec;
        
return 0;
}
