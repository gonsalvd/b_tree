all: bTree

bTree: bTree.o node.o item.o bTree_main.o
	g++ -g -std=c++0x -o bTree bTree.o item.o node.o bTree_main.o

bTree.o: bTree.cpp bTree.h
	g++ -c bTree.cpp

node.o: node.cpp node.h
	g++ -c node.cpp

item.o: item.cpp item.h
	g++ -c item.cpp

bTree_main.o: bTree_main.cpp bTree.h
	g++ -c bTree_main.cpp

clean:
	rm -rf *.o
	rm -rf bTree

    
    