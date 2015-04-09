//
//  bTree.h
//  Project2
//
//  Created by Gonsalves on 4/5/15.
//
//

#ifndef __Project2__bTree__
#define __Project2__bTree__

#include <stdio.h>
#include <string>
#include "Node.h"
#include "Item.h"
using namespace std;


class bTree
{
private:
    //Your private stuff to implement the B Tree
    int M;
public:
    //Constructor
    bTree();
    
    //Constructor2
    bTree(int size);
    
    //Destructor
    ~bTree();
    
    //Inserts the value pair into the tree
    bool insert(string key, string value);
    
    // Searches for the key in the tree, if found, it returns
    // true else returns false.
    // If the key is found, it stores the value in the *value variable
    bool find(string key, string *value);
    
    //Searches for the key and deletes it. Returns true if deletion was
    //successful, returns false if the key wasn't found
    bool delete_key(string key);
    
    // concatenates the contents of the tree from an inorder traversal
    // into an output stream with each string item followed by a
    // newline character in the stream
    string toStr();
    
};



#endif /* defined(__Project2__bTree__) */
