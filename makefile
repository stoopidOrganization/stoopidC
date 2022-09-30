CC = gcc
rm = del

compile:
	${CC} -Wall -c ./src/*.c

exe:
	${CC} -o ./build/stoopid *.o

del:
	${rm} *.o