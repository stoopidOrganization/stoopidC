CC = g++
rm = rm

compile:
	${CC} -Wall -c ./src/*.cpp
	${CC} -Wall -c ./src/cpp/*.cpp

exe:
	${CC} -o ./build/stoopid *.o

del:
	${rm} *.o