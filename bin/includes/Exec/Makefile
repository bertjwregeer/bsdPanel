OBJECTS = Exec
CXXFLAGS = -I.. -I. -Wall

all: $(OBJECTS).o

$(OBJECTS): $(OBJECTS).cc $(OBJECTS).h
	${CXX} ${CXXFLAGS} ${DEBUG} -c $(OBJECTS).cc

install: all

clean:
	/bin/rm -rf $(OBJECTS).o

cleandir: clean
