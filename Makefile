all: main


main: main.o qbGradient.o
	g++ -g -o main main.o qbGradient.o -std=c++17

main.o: main.cpp
	g++ -o main.o -c main.cpp -std=c++17

qbGradient.o: qbGradient.cpp
	g++ -o qbGradient.o -c qbGradient.cpp -std=c++17

.PHONY: clean

clean:
	rm *.o
