#include "Fork.h"

int main() {

	bsdPanel::Fork blah;
	blah.sigHandler();

	switch ( blah.doFork() ) {

	case 0:
		sleep(2);
		std::cout << "In child\n";
		_exit(1);
		break;
	case 1:
		std::cout << "In parent\n";
		sleep(50);
		break;
	default:
		break;
	}

	std::cout << "Signal Handler was called\n";

	sleep(5);
}
