OBJECTS = Pipe.o
CXXFLAGS = -I.. -I../Fork/ -Wall

all: $(OBJECTS)

Pipe.o: Pipe.cc Pipe.h
	${CXX} ${CXXFLAGS} ${DEBUG} -c Pipe.cc

install: all
