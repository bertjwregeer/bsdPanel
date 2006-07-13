CXXFLAGS=-I../bin/includes/

ForkPipeExectest: ForkPipeExectest.o 0x58-unix
	$(CXX) -I../bin/includes/ ForkPipeExectest.cc -L../bin/includes/0x58-unix/ -lx58unix -o ForkPipeExectest

0x58-unix::
	$(MAKE) -C ../bin/includes/0x58-unix/

.cc.o:
	$(CXX) -I../bin/includes/ -c $<

clean:
	rm -rf ForkPipeExectest
	rm -rf *.o
	cd ../bin/includes/0x58-unix/ && $(MAKE) clean
