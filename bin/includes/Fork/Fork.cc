#include "Fork.h"

#ifndef HAVEOWNHANDLERS
namespace sighandlers {
        static void sig_chld(int signo) 
        {
                pid_t mypid;
                int status, child_val;
        
                /* Wait for any child without blocking */
                if ((mypid = waitpid(-1, &status, WNOHANG)) < 0) {
                        return;
                }
        
                /*
                * We now have the info in 'status' and can manipulate it using
                * the macros in wait.h.
                */
                if (WIFEXITED(status))                /* did child exit normally? */
                {
                        child_val = WEXITSTATUS(status); /* get child's exit status */
                        std::cerr << "Child: " << mypid << " has exited with status: " << child_val << "\n";
                }
        }
}

#endif

int bsdPanel::Fork::doFork () {

	pid = fork();

	switch ( pid ) {
	
		case -1:
			std::cerr << "bsdPanel: Fork failed. Resource exhaustion?\n";
			bsdPanel::exit_program();
		case 0:
			return 0;
		default:
			return 1;
	}
	return 0;
}

void bsdPanel::Fork::sigHandler() {
        
        // Assign sig_chld as our SIGCHLD handler
        act.sa_handler = sighandlers::sig_chld;
        
        sigemptyset(&act.sa_mask);
        
        /*
        * We're only interested in children that have terminated, not ones
        * which have been stopped (eg user pressing control-Z at terminal)
        */
        act.sa_flags = SA_NOCLDSTOP;
        if (sigaction(SIGCHLD, &act, &oldact) < 0) {
                std::cerr << "Sigaction failed\n";
                bsdPanel::exit_program();
        }
        return;
}