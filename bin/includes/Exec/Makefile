OBJECTS = Exec
CXXFLAGS = -I.. -I. -Wall
DEPENDFILES = ../Exceptions/Exceptions.h

all: $(OBJECTS).o

$(OBJECTS).o: $(OBJECTS).cc $(OBJECTS).h $(DEPENDFILES)
	${CXX} ${CXXFLAGS} ${DEBUG} -c $(OBJECTS).cc

install: all

clean:
	/bin/rm -rf $(OBJECTS).o

cleandir: clean
