/*
 * Copyright 2005 X-Istence.com. All rights  reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and  documentation are
 * those of the authors and should not be  interpreted as representing official
 * policies, either expressed  or implied, of X-Istence.com or the bsdPanel
 * project.
 *
 * $Id$
 */

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
//			Fork();
//			~Fork() { std::cerr << "In ~Fork" << std::endl; };
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

#endif

namespace sighandlers {
	extern void sig_chld(int);
}
