clear: compile
	rm *.o
	./main

compile: object
	g++ -o main *.o
object:
	g++ -c main.cpp implementation/*.cpp

