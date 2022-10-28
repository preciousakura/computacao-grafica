clear: compile
	rm *.o
	./main

compile: object
	g++ -o  main *.o -lSDL2
object:
	g++ -c main.cpp implementation/*.cpp

