MODULE=Exec

${MODULE}/${MODULE}.o: ${MODULE}/${MODULE}.cc ${MODULE}/${MODULE}.h Fork/Fork.h Pipe/Pipe.h Exceptions/Exceptions.h
	${CXX} ${CXXFLAGS} ${DEBUG} -c ${.TARGET:S/.o$//}.cc -o ${.TARGET}

${MODULE}.clean:
	rm -f ${.TARGET:S/.clean$//}/${.TARGET:S/.clean$//}.o
