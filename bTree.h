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
//#include "Node.h"
//#include "Item.h"
using namespace std;



//So we
class bTree
{

    
private:
    //Your private stuff to implement the B Tree
    int M;
    int N;
    int HT;
    
    
    struct entry
    {
        string key;
        string item;
        struct node* next;
    };
    
    struct node
    {
        int m;
        entry *b;
        node(int M_size)
        {
            m=0;
            b=new entry[M_size];
        }
    };
    typedef node* link;

    link head;
    
    link insertR(link h, string item, int ht)
    {
        return h;
    }
//    string findR(link h, string key, int ht)
//    {
//        int j;
//            if (ht == 0)
//                for (j = 0; j < h->m; j++)
//                { if (v == h->b[j].key)
//                    return h->b[j].item; }
//            else
//                for (j = 0; j < h->m; j++)
//                    if ((j+1 == h->m) || (v < h->b[j+1].key))
//                        return searchR(h->b[j].next, v, ht-1);
//            return nullItem;
//        
//    }
    
public:
    //Constructor
    bTree();
    
    //Constructor2
    bTree(int size)
    {
        //no error handling here if you put in negative size, etc. not needed?
        M = size;
        N = 0;
        HT = 0;
        head = new struct node(size);
    }
    
    //Destructor
    ~bTree()
    {
        
    }
    
    //Inserts the value pair into the tree
    bool insert(string key, string item)
    {
        node* u = insertR(head, item, HT);
        if (u == 0) return true;
        struct node* t = new node(M);
        t->m = 2;
        t->b[0].key = head->b[0].key;
        t->b[1].key = u->b[0].key;
        //t->b[0].next = head;
        //t->b[1].next = u;
        head = t;
        HT++;
        return true;
    }
    
    // Searches for the key in the tree, if found, it returns
    // true else returns false.
    // If the key is found, it stores the value in the *value variable
    bool find(string key, string *value)
    {
        return true;
    }
    
    //Searches for the key and deletes it. Returns true if deletion was
    //successful, returns false if the key wasn't found
    bool delete_key(string key)
    {
        return true;
    }
    
    // concatenates the contents of the tree from an inorder traversal
    // into an output stream with each string item followed by a
    // newline character in the stream
    string toStr()
    {
        return "drew";
    }
    
};



#endif /* defined(__Project2__bTree__) */
