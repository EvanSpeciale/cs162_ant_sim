main: main.o Ant.o Menu.o
	g++ -std=c++11 main.o Ant.o Menu.o -o main

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -std=c++11 -c Ant.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++11 -c Menu.cpp

clean:
	rm *.o main
