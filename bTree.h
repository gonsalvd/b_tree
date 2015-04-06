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
using namespace std;

#endif /* defined(__Project2__bTree__) */

int M = 8;
int N;
int HT;

//p412
static int maxKey = 1000;

typedef int Key;
class Item
{
private:
    Key keyval;
    float info;
public:
    Item()
    {
        keyval = maxKey;
    }
    Key key()
    {
        return keyval;
    }
    int null()
    {
        return keyval == maxKey;
    }
    //    void rand()
    //    { keyval = 1000*::rand()[/]RAND_MAX;
    //        info = 1.0*::rand()[/]RAND_MAX; }
    //    int scan(istream& is = cin)
    //    { return (is >> keyval >> info) != 0; }
    //    void show(ostream& os = cout)
    //    { os << keyval << ["] ["] << info << endl; }
};
//ostream& operator<<(ostream& os, Item& x)
//{ x.show(os); return os; }

template <class Item, class Key>
struct entry
{
    Key key;
    Item item;
    struct node *next;
};

struct node
{
    node()
    {
        m = 0;
    }
    int m;
    entry<Item,Key> b[M];
    
};

typedef node *link;




class bTree
{
    
    
    Item nullItem;
    link head;
    
    
private:
    //Your private stuff to implement the B Tree
    
    //Node Split
    link split(link h)
    {
        link t = new node();
        for (int j = 0; j < M/2; j++)
        {
            t->b[j] = h->b[M/2+j];
        }
        h->m = M/2;
        t->m = M/2;
        return t;
    };
    
    link insertR(link h, Item x, int ht)
    {
        int i, j;
        Key v = x.key();
        entry<Item, Key> t;
        t.key = v;
        t.item = x;
        if (ht == 0)
        {
            for (j = 0; j < h->m; j++)
            {
                if (v < h->b[j].key)
                {
                    break;
                }
            }
        }
        else
            for (j = 0; j < h->m; j++)
            {
                if ((j+1 == h->m) || (v < h->b[j+1].key))
                {
                    link u;
                    u = insertR(h->b[j++].next, x, ht-1);
                    if (u == 0)
                    {
                        return 0;
                    }
                    t.key = u->b[0].key;
                    t.next = u;
                    break;
                }
            }
        for (i = h->m; i > j; i--)
        {
            h->b[i] = h->b[i-1];
        }
        h->b[j] = t;
        if (++h->m < M)
        {
            return 0;
        }
        else
        {
            return split(h);
        }
    }
    
    Item searchR(link h, Key v, int ht)
    {
        int j;
        if (ht == 0)
        {
            for (j = 0; j < h->m; j++)
            {
                if (v == h->b[j].key)
                {
                    return h->b[j].item;
                }
            }
        }
        else
        {
            for (j = 0; j < h->m; j++)
            {
                if ((j+1 == h->m) || (v < h->b[j+1].key))
                {
                    return searchR(h->b[j].next, v, ht-1);
                }
            }
            
            return nullItem;
        }
    }
    
public:
    
    
    //Constructor
    bTree(int maxN)
    {
        N = 0;
        //M=nullItem.key();
        HT = 0;
        head = new node;
    }
    
    //Destructor
    ~bTree();
    
    //Inserts the value pair into the tree
    bool insert(string key, string value);
    void insert(Item item)
    {
        link u = insertR(head, item, HT);
        if (u == 0)
        {
            return;
        }
        link t = new node();
        t->m = 2;
        t->b[0].key = head->b[0].key;
        t->b[1].key = u->b[0].key;
        t->b[0].next = head; t->b[1].next = u;
        head = t;
        HT++;
    }
    
    // Searches for the key in the tree, if found, it returns
    // true else returns false.
    // If the key is found, it stores the value in the *value variable
    bool find(string key, string *value);
    
    Item search(Key v)
    {
        return searchR(head, v, HT);
    }
    
    //Searches for the key and deletes it. Returns true if deletion was
    //successful, returns false if the key wasn't found
    bool delete_key(string key);
    
    // concatenates the contents of the tree from an inorder traversal
    // into an output stream with each string item followed by a
    // newline character in the stream
    string toStr();
    
};
