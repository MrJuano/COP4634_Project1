main: myshell.o parse.o
	g++ -o myshell myshell.o parse.o
	./myshell
	$(RM) -rf *.o myshell

parse.o: parse.cpp parse.hpp
	g++ -std=c++14 -c parse.cpp

myshell.o: myshell.cpp parse.hpp
	g++ -std=c++14 -c myshell.cpp

clean:
	rm -rf *.o myshell
