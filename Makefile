output: main.o
	g++ main.o -o main
main.o: src/main.cpp
	g++ -c src/main.cpp
clean:
	rm *.o main
