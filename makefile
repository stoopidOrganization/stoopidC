CC = g++
rm = rm

compile:
	${CC} -Wall -c ./src/*.cpp

exe:
	${CC} -o ./build/stoopid *.o

del:
	${rm} *.o