CC = g++

compile-linux:
	${CC} -Wall -c ./src/*.cpp
	${CC} -Wall -c ./src/cpp/*/*.cpp
	${CC} -Wall -c ./src/c/*/*.c

compile-windows:
	${CC} -Wall -c ./src/*.cpp

	${CC} -Wall -c ./src/cpp/bools/*.cpp
	${CC} -Wall -c ./src/cpp/math/*.cpp
	${CC} -Wall -c ./src/cpp/strings/*.cpp
	${CC} -Wall -c ./src/cpp/utils/*.cpp
	${CC} -Wall -c ./src/cpp/variables/*.cpp

	${CC} -Wall -c ./src/c/cBools/*.c
	${CC} -Wall -c ./src/c/cMath/*.c

exe:
	${CC} -o ./build/stoopid *.o

rm:
	rm *.o

del:
	del *.o