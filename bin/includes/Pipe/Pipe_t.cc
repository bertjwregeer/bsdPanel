#include <iostream>
#include "Pipe.h"

int main() {
        
        std::cerr << "Pipe_t started" << std::endl;

        bsdPanel::Pipe mypipe;
        mypipe.sigHandler();
        
        switch ( mypipe.doPipe() ) {
                case 0:
                        {
                        std::cerr << "In child" << std::endl;
                        
                        // execlp("cat", "cat", NULL);
                        
                        execlp("ls", "ls", "-alh", NULL);
                        _exit(0);
                        break; 
                        }
                case 1:
                        {
                        std::cerr << "In parent" << std::endl;
                        std::string data;
			std::string gotwhat;
			
			// std::cout << "Enter some random info to send over to cat" << std::endl;
			// std::getline(std::cin, data);
			
			// mypipe.write(data.append("\n"));
                        
			mypipe.read(gotwhat);
                        std::cerr << "data contains: " << gotwhat << std::endl;
                        mypipe.read(gotwhat);
                        std::cerr << "data contains: " << gotwhat << std::endl;
                        mypipe.read(gotwhat);
                        std::cerr << "data contains: " << gotwhat << std::endl;
                        mypipe.read(gotwhat);
                        std::cerr << "data contains: " << gotwhat << std::endl;
                        mypipe.read(gotwhat);
                        std::cerr << "data contains: " << gotwhat << std::endl;
                        mypipe.read(gotwhat);
                        std::cerr << "data contains: " << gotwhat << std::endl;
                        mypipe.read(gotwhat);
                        std::cerr << "data contains: " << gotwhat << std::endl;
                        mypipe.read(gotwhat);
                        std::cerr << "data contains: " << gotwhat << std::endl;
                        mypipe.read(gotwhat);
                        std::cerr << "data contains: " << gotwhat << std::endl;
                        mypipe.read(gotwhat);
                        std::cerr << "data contains: " << gotwhat << std::endl;
                        mypipe.read(gotwhat);
                        std::cerr << "data contains: " << gotwhat << std::endl;
                        mypipe.read(gotwhat);
                        std::cerr << "data contains: " << gotwhat << std::endl;
                        
                        break;
                        }
                default:
                        bsdPanel::exit_program();
        }

}
