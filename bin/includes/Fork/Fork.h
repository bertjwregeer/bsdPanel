#ifndef BSDPANEL_FORK
#define BSDPANEL_FORK

#include <sys/types.h>
#include <sys/wait.h>   /* header for waitpid() and various macros */
#include <signal.h>     /* header for signal functions */
#include <unistd.h>
#include <iostream>
#include "bsdPanelInc.h"

namespace bsdPanel {
	class Fork {
		public:
			Fork();
			virtual ~Fork() = 0;
			int doFork();
			
			/*
			 * sighandler should be created by main(), as that
			 * is the only place in the app that has intimate
			 * knowledge of the way Fork is stored somewhere
			 * 
			 * We assign the signal handling to 
			 * sighandlers::sig_chld. Define HAVEOWNHANDLERS
			 * and create your own sighandlers::sig_chld
			 * and we will use that instead of the one we
			 * have standard.
			 */
			 
			void sigHandler();
                private:
                        pid_t pid;
                        int dead;
                        struct sigaction act;
                        struct sigaction oldact;
	};
}

bsdPanel::Fork::~Fork() {};

#endif