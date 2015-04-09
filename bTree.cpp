//
//  bTree.cpp
//  Project2
//
//  Created by Gonsalves on 4/5/15.
//
//

#include "bTree.h"

//Constructor
bTree::bTree(void)
{
    //Default size constructor
    M = 5;
}

//Constructor2
bTree::bTree(int size)
{
    //no error handling here if you put in negative size, etc. not needed?
    M = size;
}

//Destructor
bTree::~bTree(void)
{
    
}

//Inserts the value pair into the tree
bool bTree::insert(string key, string value)
{
    return false;
}

// Searches for the key in the tree, if found, it returns
// true else returns false.
// If the key is found, it stores the value in the *value variable
bool bTree::find(string key, string *value)
{
    return false;
}

//Searches for the key and deletes it. Returns true if deletion was
//successful, returns false if the key wasn't found
bool bTree::delete_key(string key)
{
    return false;
}

// concatenates the contents of the tree from an inorder traversal
// into an output stream with each string item followed by a
// newline character in the stream
string bTree::toStr()
{
    return "TEST";
}