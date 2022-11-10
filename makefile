CC = g++
rm = rm

compile:
	${CC} -Wall -c ./src/*.cpp
	${CC} -Wall -c ./src/cpp/*.cpp
	${CC} -Wall -c ./src/c/*.c

exe:
	${CC} -o ./build/stoopid *.o

del:
	${rm} *.o