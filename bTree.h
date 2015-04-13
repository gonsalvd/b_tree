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
    string contents;
    
    //These are internal structs
    struct node;
    //Entry is an entry in a node that has information about the key, item and pointer to the next node
    struct entry
    {
        string key;
        string item;
        node* next;
    };
    //Node is a node within a bTree
    struct node
    {
        //M is the max number of entries in a node, m is current number of entries (<=M-1)
        int m;
        //This is an array of entry pointers (up to M-1)
        entry* b;
        //Constructor for a node, takes in the M of the bTree
        node(int M_size)
        {
            //Intial nodes have no entries, thus m=0
            m=0;
            b=new entry[M_size];
        }
    };
    //The book used something like this to help us manage our language
    //typedef means that link essentially means 'node*' which is a node pointer.
    typedef node* link;
    
    //this is actually (node* head)
    link head;
    
    //manages all inserts into the bTree with current link, insert key/item value, and the current search height level=ht
    link insertR(link h, string key, string item, int ht)
    {
        int i, j;
        string v = key;
        //here we create a new 'entry' for our inserted key/item values
        entry t;
        t.key = v;
        t.item = item;
        //WE ONLY WORK IN THE LOWEST LEVEL LEAVES OF A BTREE. IF HT=3, THEN THE ROOT IS AT 3, AND WE ONLY WANT TO SEARCH IN ht=0. remember there is some duplicity of key values because higher levels have links to lower values. if we allowed ourselves to search and return from ht>0 then we would get duplicate insert results
        if (ht == 0)
            //search through this node from [0] to [m-1]
            for (j = 0; j < h->m; j++)
            {
                //if our searched key value is less than the value at [j] then break and go down to "SHIFT" (below ~10 lines)
                if (v < h->b[j].key)
                    break;
            }
        //He we would be looking at a ht>0. we recursively will look until ht=0 (like in the above IF code)
        else
            //look through this node (at ht>0) from [0] to [m-1]
            for (j = 0; j < h->m; j++)
                //check two cases, 1)"j+1 == h->m" means we are at the end of this node meaning we are looking at the last entry of the node or 2)v, our searched key value is less than the ****
                if ((j+1 == h->m) || (v < h->b[j+1].key))
                {
                    //create a new 'node*'
                    link u;
                    u = insertR(h->b[j++].next, key, item, ht-1);
                    if (u == 0)
                        return 0;
                    t.key = u->b[0].key;
                    t.next = u;
                    break;
                }
        //"SHIFT" code. Here we make space to insert our new entry t
        //Go through the loop, shifting stuff to the right
        for (i = h->m; i > j; i--)
            h->b[i] = h->b[i-1];
        //now that we have made space we will insert entry t in its proper place
        h->b[j] = t;
        
        //here we are checking if our node is full. remember each node can technically hold M entries, but we limit this to M-1 in our Bottom Up approach. Here we check to see that adding our newest entry still keeps m < M or m <= M-1.
        if (++h->m < M)
            //Return 0 means it was inserted properly, go to the public insert()
            return 0;
        //if we found that our node is full then we much split the node
        else
            return split(h);
        
    }
    
    //this splits our nodes with full nodes
    link split(link h)
    {
        //we create a new node
        link t = new node(M);
        //we move the larger half of our node to the new node t
        for (int j = 0; j < M/2; j++)
            //kind of confusing but this moves the larger half of the old node to the first positions of the new node
            //eg M=5, old node has up to 4 entries from j=0,1,2,3
            //in our for loop, j will take on values 0,1
            //M/5(floor) = 2
            //we want to move j=2,3 to new 0,1 positions of t
            t->b[j] = h->b[M/2+j];
        //here we set the number of entries of the old node
        //from our example the size of m for our old array is now 2 and REMEMBER that we didnt set those j=2,3 positions in our old node to "" or "empty". the values still exisit there. no zeroing was done
        h->m = M/2;
        //we set the size number of entries of the new node, t
        t->m = M/2;
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
    bool deleteR(link h, string key, int ht)
    {
        int j;
        //string no_string;
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
                        //Shift our elements to fill hole
                        for (int i = h->m; i > j; i--)
                            h->b[i] = h->b[i-1];
                    }
                    //Because we removed an entry we decrement our m counter for h.
                    --h->m;
                    return true;

                }
            }
        else
            for (j = 0; j < h->m; j++)
                if ((j+1 == h->m) || (key < h->b[j+1].key))
                    return deleteR(h->b[j].next, key, ht-1);
        return false;
    }
    
    void printR(link h,int ht)
    {
        cout<<"here1"<<endl;
        cout<<"height:"<<ht<<endl;
        int j;
        //string contents;
        if (ht == 0)
            for (j = 0; j < h->m; j++)
            {
                cout<<"here"<<endl;
                contents += h->b[j].key + '\n';
                cout<<"contents:"<<contents<<endl;
            }
        else
//            for (j = 0; j < h->m; j++)
//                if ((j+1 == h->m) || (key < h->b[j+1].key))
                    printR(h->b[j].next, ht-1);
        //return contents;
    }
    
public:
    //Constructor
    bTree()
    {
        //Random default variables in case bTree is not initalized
        M = 5;
        N = 0;
        HT = 0;
        head = new node(M);
    }
    
    //Constructor2
    bTree(int size)
    {
        //no error handling here if you put in negative size, etc. not needed?
        //M is the num of entries each node can take. we only fill up to M-1 entries in our Bottom Up approach (add item, then split NOT split, then add)
        M = size;
        //N is the total number of keys/items in our entire BTree
        N = 0;
        //HT is the number of levels in our bTree
        HT = 0;
        //Head is the root
        head = new node(M);
    }
    
    //Destructor
    ~bTree()
    {
        
    }
    
    //Inserts the value pair into the tree
    bool insert(string key, string item)
    {
        //new node?
        link u = insertR(head, key, item, HT);
        //It was inserted
        if (u == 0)
            return true;
        //WE GET HERE ONLY IF WE ENDED UP SPLITTING in insertR(). now we have an old node, a new node, and we need now a parent node to link the old and new nodes together
        //Link t is the new PARENTS node our our old and new node
        link t = new node(M);
        //The new parent node is going to have a an entry pointing to the old nodes [0] and a second sentry pointing to the new nodes [0]
        t->m = 2;
        //Assign the first entry key of the parent node to the first of the old node
        t->b[0].key = head->b[0].key;
        //Assign the second entry key of the parent node to the first of the new node
        t->b[1].key = u->b[0].key;
        //Now patch the links, "head" is the old node, u is the new node
        t->b[0].next = head;
        t->b[1].next = u;
        //Reassign head to be the new parent node, t
        head = t;
        //We have grown our tree by one level so now the Btrees overall HT is increased (HT++)
        HT++;
        //Insertion was successful
        return true;
    }
    
    // Searches for the key in the tree, if found, it returns
    // true else returns false.
    // If the key is found, it stores the value in the *value variable
    bool find(string key, string* value)
    {
        //this is a check value against an empty string that findR will return
        string no_value;
        //the string* returned will either be empty or have a value
        //findR is a private method that handles the internal searching of the bTree
        *value = findR(head,key,HT);
        //if we return an item value, then it means it was found
        if(*value != no_value)
        {
            //if we return true then the key was found so the item will be printed
            return true;
        }
        //this is the case that the key was not found
        return false;
    }
    
    //Searches for the key and deletes it. Returns true if deletion was
    //successful, returns false if the key wasn't found
    bool delete_key(string key)
    {
        //private bool deleteR function
        if (deleteR(head, key,HT))
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
        printR(head, HT);
        //cout<<"drew1"<<endl;

        //FOR TESTING ONLY!
        return contents;
    }
    
};



#endif /* defined(__Project2__bTree__) */
