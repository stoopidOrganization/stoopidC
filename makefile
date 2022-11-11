CC = g++

compile:
	${CC} -Wall -c ./src/*.cpp
	${CC} -Wall -c ./src/cpp/*/*.cpp
	${CC} -Wall -c ./src/c/*/*.c

exe:
	${CC} -o ./build/stoopid *.o

rm:
	rm *.o

del:
	del *.o