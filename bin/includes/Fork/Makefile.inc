MODULE=Fork

${MODULE}/${MODULE}.o: ${MODULE}/${MODULE}.cc ${MODULE}/${MODULE}.h
	${CXX} ${CXXFLAGS} ${DEBUG} -c ${.TARGET:S/.o$//}.cc -o ${.TARGET}

${MODULE}.clean:
	rm -f ${.TARGET:S/.clean$//}/${.TARGET:S/.clean$//}.o
