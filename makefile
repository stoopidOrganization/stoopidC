CC = g++
rm = rm

compile:
	${CC} -Wall -c ./src/*.cpp
	${CC} -Wall -c ./src/cpp/math/*.cpp
	${CC} -Wall -c ./src/cpp/stringHandler/*.cpp
	${CC} -Wall -c ./src/cpp/utils/*.cpp
	${CC} -Wall -c ./src/cpp/variables/*.cpp
	${CC} -Wall -c ./src/c/cMath/*.c

exe:
	${CC} -o ./build/stoopid *.o

del:
	${rm} *.o