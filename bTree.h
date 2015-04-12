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
    
    struct node;
    struct entry
    {
        string key;
        string item;
        //or struct node* next
        node* next;
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
    typedef struct node* link;
    
    link head;
    
    link insertR(link h, string key, string item, int ht)
    {
        int i, j;
        string v = key;
        entry t;
        t.key = v; t.item = item;
        if (ht == 0)
            for (j = 0; j < h->m; j++)
            { if (v < h->b[j].key) break; }
        else
            for (j = 0; j < h->m; j++)
                if ((j+1 == h->m) || (v < h->b[j+1].key))
                {
                    link u;
                    //struct node* test = h->b[j++].next;
                    u = insertR(h->b[j++].next, key, item, ht-1);
                    if (u == 0) return 0; t.key = u->b[0].key;
                    t.next = u;
                    break;
                }
        for (i = h->m; i > j; i--) h->b[i] = h->b[i-1];
        h->b[j] = t;
        if (++h->m < M) return 0; else return split(h);
        
    }
    
    link split(link h)
    {
        link t = new node(M);
        for (int j = 0; j < M/2; j++)
            t->b[j] = h->b[M/2+j];
        h->m = M/2; t->m = M/2;
        return t;
    }
    
    string findR(link h, string key, int ht)
    {
        int j;
        string no_string;
        if (ht == 0)
            for (j = 0; j < h->m; j++)
            { if (key == h->b[j].key)
                return h->b[j].item; }
        else
            for (j = 0; j < h->m; j++)
                if ((j+1 == h->m) || (key < h->b[j+1].key))
                    return findR(h->b[j].next, key, ht-1);
        return no_string;
        
    }
    
    //same as findR
    string deleteR(link h, string key, int ht)
    {
        int j;
        string no_string;
        if (ht == 0)
            for (j = 0; j < h->m; j++)
            {
                if (key == h->b[j].key)
                    //key difference from findR
                    //first set that location to empty, then shift the array and dont worry about resizing the arrays
                {
                    h->b[j].item = "";
                    //if we are deleting the last item in the node then we dont want to step out of bounds, check first. IS THIS NEEDED?
                    if(j < h->m)
                    {
                        for (int i = h->m; i > j; i--)
                            h->b[i] = h->b[i-1];
                    }
                    --h->m;
                }
                return "Deleted";
            }
        else
            for (j = 0; j < h->m; j++)
                if ((j+1 == h->m) || (key < h->b[j+1].key))
                    return findR(h->b[j].next, key, ht-1);
        return no_string;
    }
    
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
        node* u = insertR(head, key, item, HT);
        if (u == 0) return true;
        struct node* t = new node(M);
        t->m = 2;
        t->b[0].key = head->b[0].key;
        t->b[1].key = u->b[0].key;
        t->b[0].next = head;
        t->b[1].next = u;
        head = t;
        HT++;
        return true;
    }
    
    // Searches for the key in the tree, if found, it returns
    // true else returns false.
    // If the key is found, it stores the value in the *value variable
    bool find(string key, string* value)
    {
        string no_value;
        *value = findR(head,key,HT);
        if(*value != no_value)
        {
            return true;
        }
        return false;
    }
    
    //Searches for the key and deletes it. Returns true if deletion was
    //successful, returns false if the key wasn't found
    bool delete_key(string key)
    {
        if (deleteR(head, key,HT) == "Deleted")
        {
            //THIS IS FOR TESTING ONLY
            cout<<"Deleted key: "<<key<<endl;
            return true;
        }
        return false;
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
