#include "Pipe.h"

int bsdPanel::Pipe::doPipe() {
	if ( pipe(to) == -1) {
		std::cerr << "Creating pipe failed. Resource exhaustion?";
		bsdPanel::exit_program();
	}

	if ( pipe(from) == -1) {
		std::cerr << "Creating pipe failed. Resource exhaustion?";
		bsdPanel::exit_program();
	}

	switch ( doFork() ) {
		case 0:
			close(to[1]);
			close(from[0]);
			dup2(to[0], 0);
			dup2(from[1], 1);
			return 0;
		case 1:
			close(to[0]);
			close(from[1]);
			return 1;
		default:
			bsdPanel::exit_program();
	}
	return 0; // We should never get here!
} 

std::istream& bsdPanel::operator >>(std::istream& is, bsdPanel::Pipe& myPipe) {
        std::string sendOver;
        
        std::getline(is, sendOver);
        sendOver.append("\n");
        
        ssize_t nwritten = 0, n, nbyte = sendOver.length();
        
        do {
                if((n = write(myPipe.to[0], sendOver.c_str() + nwritten, (nbyte - nwritten))) == -1) {
                        if (errno == EINTR) {
                                continue;
                        } else {
                                std::cerr << "Unable to write to pipe.\n"; 
                                break;
                        }
                }
                nwritten += n;
                
        } while (nwritten < nbyte);
        
        return is;             
}