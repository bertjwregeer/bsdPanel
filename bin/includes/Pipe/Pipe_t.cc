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
                        
                        execlp("cat", "cat", NULL);
                        
                        _exit(0);
                        break; 
                        }
                case 1:
                        {
                        std::cerr << "In parent" << std::endl;
                        std::string data;
			
			mypipe.write("Hello, i am here!!!\n");

                        mypipe.read(data);
                        
                        std::cerr << "data contains: " << data << std::endl;
                        break;
                        }
                default:
                        bsdPanel::exit_program();
        }

}
