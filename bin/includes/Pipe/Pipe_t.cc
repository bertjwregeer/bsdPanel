#include <iostream>
#include "Pipe.h"

int main() {
        
        std::cerr << "Pipe_t started" << std::endl;

        bsdPanel::Pipe mypipe;
        // mypipe.sigHandler();
        
        switch ( mypipe.doPipe() ) {
                case 0:
                        {
                        sleep(5);
                        
                        std::cerr << "In child" << std::endl;
                        
                        std::cout << "Hello?";
                        std::string something;
                        
                        std::cin >> something;
                        
                        std::cerr << "Something contains: " << something << std::endl;
                        sleep(10);
                        _exit(0);
                        break; 
                        }
                case 1:
                        {
                        std::cerr << "In parent" << std::endl;
                        std::string data;
                        
                        mypipe.read(data);
                        
                        std::cerr << "data contains: " << data << std::endl;
                        
                        mypipe.write("I am here");
                        
                        sleep(10);
                        }
                default:
                        bsdPanel::exit_program();
        }

}