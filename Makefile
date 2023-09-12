
myshell: myshell.o parse.o
	g++ -o myshell myshell.o parse.o

parse.o: parse.cpp parse.hpp
	g++ -std=c++14 -Wall -c parse.cpp

myshell.o: myshell.cpp parse.hpp
	g++ -std=c++14 -Wall -c myshell.cpp

clean:
	rm -rf *.o myshell
