DIRS= Fork Pipe Exec Parser
OPTIMIZE ?= -O0
CXXFLAGS = -I. -Wall ${OPTIMIZE}
CLEANUP=
BUILDALL=

doall: all

.for doinc in ${DIRS}
.include "${doinc}/Makefile.inc"
CLEANUP+= ${doinc}.clean
BUILDALL+= ${doinc}/${doinc}.o
.endfor

all: $(BUILDALL)

clean: $(CLEANUP)

