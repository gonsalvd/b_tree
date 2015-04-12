all: bTree

bTree: bTree.o node.o item.o bTree_main.o
	g++ -g -std=c++0x -o bTree bTree.o node.o item.o bTree_main.o

bTree.o: bTree.cpp bTree.h
	g++ -c bTree.cpp

node.o: Node.cpp Node.h
	g++ -c Node.cpp

item.o: Item.cpp Item.h
	g++ -c Item.cpp

bTree_main.o: bTree_main.cpp bTree.h
	g++ -c bTree_main.cpp

clean:
	rm -rf *.o
	rm -rf bTree

    
    