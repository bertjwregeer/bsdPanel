#ifndef BSDPANEL_PIPE
#define BSDPANEL_PIPE

#include <sstream>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include "bsdPanelInc.h"
#include "Fork.h"

namespace bsdPanel {
	class Pipe : public bsdPanel::Fork {
		public:	
			Pipe();
			virtual ~Pipe() = 0;
			int doPipe();
			friend std::istream& operator >>(std::istream& is, bsdPanel::Pipe& myPipe);
                private:
                        int to[2];
                        int from[2];
	};
}

bsdPanel::Pipe::~Pipe() {
        // Close any and all pipes. Don't care if it fails or not
        close(to[0]);
        close(to[1]);
        close(from[0]);
        close(from[1]);
}
	
#endif