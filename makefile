all: bTree

bTree: bTree.o bTree_main.o
	g++ -g -std=c++0x -o bTree bTree.o bTree_main.o

bTree.o: bTree.cpp bTree.h
	g++ -c bTree.cpp

bTree_main.o: bTree_main.cpp bTree.h
	g++ -c bTree_main.cpp

clean:
	rm -rf *.o
	rm -rf bTree