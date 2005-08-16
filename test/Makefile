ForkPipeExectest: ForkPipeExectest.cc
	cd ../bin/includes/; $(MAKE)
	$(CXX) -I../bin/includes/ ../bin/includes/Fork/Fork.o ../bin/includes/Pipe/Pipe.o ../bin/includes/Exec/Exec.o ForkPipeExectest.cc -o ForkPipeExectest

clean:
	rm -rf ForkPipeExectest
