ForkPipeExectest: ForkPipeExectest.cc includes
	$(CXX) -I../bin/includes/ ../bin/includes/Fork/Fork.o ../bin/includes/Pipe/Pipe.o ../bin/includes/Exec/Exec.o ForkPipeExectest.cc -o ForkPipeExectest

Parsertest: Parsertest.cc includes
	$(CXX) -ggdb -g -I../bin/includes/ ../bin/includes/Parser/Parser.o Parsertest.cc -o Parsertest

includes::
	cd ../bin/includes/; $(MAKE)

clean:
	rm -rf ForkPipeExectest
	rm -rf Parsertest
	rm -rf *.core
