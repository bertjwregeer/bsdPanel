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
                        
                        execl("/bin/echo", "echo", "This", "is", "a", "bloody", "test", NULL);
                        
                        _exit(0);
                        break; 
                        }
                case 1:
                        {
                        std::cerr << "In parent" << std::endl;
                        std::string data;

                        mypipe.read(data);
                        
                        std::cerr << "data contains: " << data << std::endl;
                        
                        }
                default:
                        bsdPanel::exit_program();
        }

}