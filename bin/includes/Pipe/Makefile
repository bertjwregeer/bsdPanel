OBJECTS = Pipe.o
CXXFLAGS = -I. -I.. -I../Fork/ -Wall
CLEANFILES = Pipe_t
REQUIRE = Fork sighandler

all: $(OBJECTS)

Pipe.o: Pipe.cc Pipe.h pipestream.h
	${CXX} ${CXXFLAGS} ${DEBUG} -c Pipe.cc

install: all

clean:
	/bin/rm -rf *.o $(CLEANFILES)

cleandir: clean


Pipe_t: Pipe.o Pipe_t.cc
#	@${ECHO_CMD} "===> Compiling test for the Pipe class."
	${CXX} ${CXXFLAGS} ${DEBUG} Pipe_t.cc Pipe.o ../Fork/Fork.o -o Pipe_t
#	@${ECHO_CMD} "===> Done. Run it with make testrun"

test: Pipe_t

testrun: test
	/bin/sh -c './Pipe_t'

