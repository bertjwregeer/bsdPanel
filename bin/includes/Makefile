DIRS= Fork Pipe Exec
CXXFLAGS = -I. -Wall
CLEANUP=
BUILDALL=

doall: all

.for doinc in ${DIRS}
.include "${doinc}/Makefile.inc"
CLEANUP+= ${doinc}.clean
BUILDALL+= ${doinc}/${doinc}.o
.endfor

clean: $(CLEANUP)

all: $(BUILDALL)
