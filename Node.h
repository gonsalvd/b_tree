//
//  node.h
//  Project2
//
//  Created by Gonsalves on 4/8/15.
//
//

#ifndef __Project2__node__
#define __Project2__node__

#include <stdio.h>
#include <string>
#include "Item.h"

//class Node;
class Item;
//{
//public:
//    string key_value;
//    string info_value;
//    Node *next;
//    Item();
//    //    Item(string key, string value)
//    //    {
//    //        key_value = key;
//    //        info_value = value;
//    //    };
//    string key();
//    string info();
//};

class Node
{
public:
    int m;
    Item *b;
    Node(int size)
    {
        m=0;
        b=new Item[size];
    }
};

#endif /* defined(__Project2__node__) */