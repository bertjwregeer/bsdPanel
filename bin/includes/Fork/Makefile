OBJECTS = Fork.o
CXXFLAGS = -I.. -Wall
CLEANFILES=Fork_t
REQUIRE = sighandler

all: $(OBJECTS)

Fork.o: Fork.cc Fork.h
	${CXX} ${CXXFLAGS} ${DEBUG} -c Fork.cc

install: all

clean:
	/bin/rm -rf *.o $(CLEANFILES)

cleandir: clean

Fork_t: Fork.o Fork_t.cc
	${CXX} ${CXXFLAGS} ${DEBUG} Fork_t.cc ../sighandler.o Fork.o -o Fork_t

test: Fork_t

testrun: test
	/bin/sh -c './Fork_t'
