OBJECTS = Pipe
CXXFLAGS = -I.. -I. -Wall

all: $(OBJECTS).o

$(OBJECTS).o: $(OBJECTS).cc $(OBJECTS).h
	${CXX} ${CXXFLAGS} ${DEBUG} -c $(OBJECTS).cc

install: all

clean:
	/bin/rm -rf $(OBJECTS).o

cleandir: clean
