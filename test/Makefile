CXXFLAGS=-I../bin/includes/

ForkPipeExectest: ForkPipeExectest.o includes
	$(CXX) $(DEBUG) -I../bin/includes/ ForkPipeExectest.cc -L../bin/includes/0x58-unix/ -lx58unix -o ForkPipeExectest

Configtest: Configtest.o includes
	$(CXX) $(DEBUG) -I../bin/includes ../bin/includes/Config.o Configtest.o -o Configtest

includes::
	$(MAKE) -C ../bin/includes/

.cc.o:
	$(CXX) $(DEBUG) -I../bin/includes/ -c $<

clean:
	rm -f Configtest
	rm -f ForkPipeExectest
	rm -f *.o
	-rm -i *.core
	$(MAKE) -C../bin/includes/ rclean
