all:hw4
	./hw4

hw4: main.o lib.o
	g++ main.o lib.o -o hw4	
	
hw4_main.o: main.cpp
	g++ -std=c++11 -c main.cpp
hw4_lib.o: lib.cpp
	g++ -std=c++11 -c lib.cpp
