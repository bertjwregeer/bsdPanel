#include "Fork.h"

int main() {

	bsdPanel::Fork blah;
	blah.sigHandler();
	int i;	

	for (i = 0; i < 10; i++)
	switch ( blah.doFork() ) {

	case 0:
		sleep(5);
		std::cout << "In child" << std::endl;
		_exit(600);
		break;
	case 1:
		std::cout << "In parent" << std::endl;
		sleep(2);
		break;
	default:
		break;
	}

	std::cout << "Signal Handler was called" << std::endl;
}
