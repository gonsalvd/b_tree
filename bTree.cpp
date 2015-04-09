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
    N = 0;
    HT = 0;
    head = new Node(M);
}

//Constructor2
bTree::bTree(int size)
{
    //no error handling here if you put in negative size, etc. not needed?
    M = size;
    N = 0;
    HT = 0;
    head = new Node(M);
}

//Destructor
bTree::~bTree(void)
{
    
}

link bTree::insertR(link h, Item x, int ht)
{
    return h;
}

//Inserts the value pair into the tree
bool bTree::insert(string key, string value)
{
    Item *it = new Item();
    it->key_value = key;
    it->info_value = value;
    link u = insertR(head, *it, HT);
    if (u == 0) return true;
    link t = new Node(M); t->m = 2;
    t->b[0].key_value  = head->b[0].key_value;
    t->b[1].key_value = u->b[0].key_value;
    t->b[0].next = head; t->b[1].next = u;
    head = t;
    HT++;
    return true;
    
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