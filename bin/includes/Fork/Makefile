OBJECTS = Fork.o
CXXFLAGS = -I.. -Wall
CLEANFILES=Fork_t


all: $(OBJECTS)

Fork.o: Fork.cc Fork.h
	${CXX} ${CXXFLAGS} ${DEBUG} -c Fork.cc

install: all

clean:
	/bin/rm -rf *.o $(CLEANFILES)

cleandir: clean

Fork_t: Fork.o Fork_t.cc
	@${ECHO} "===> Compiling test for the Fork class."
	${CXX} ${CXXFLAGS} ${DEBUG} Fork_t.cc Fork.o -o Fork_t
	@${ECHO} "===> Done. Run it with make testrun"

test: Fork_t

testrun: test
	/bin/sh -c './Fork_t'
