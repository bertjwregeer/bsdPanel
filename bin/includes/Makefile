OPTIMIZE ?=0
CXXFLAGS = -Wall -pipe -O${OPTIMIZE} ${DEBUG}

ALL = 0x58-unix Config.o

all: ${ALL}

0x58-unix::
	$(MAKE) -C ./0x58-unix/

Config.o: Config.cc Config.h

.cc.o:
	$(CXX) ${CXXFLAGS} -c $<
	
clean:
	/bin/rm -f *.o

rclean: clean
	$(MAKE) -C ./0x58-unix/ clean