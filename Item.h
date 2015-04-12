//
//  item.h
//  Project2
//
//  Created by Gonsalves on 4/8/15.
//
//

#ifndef __Project2__item__
#define __Project2__item__

#include <stdio.h>
#include <string>
#include "Node.h"
using namespace std;

//an item is what we are storing in our array in the b-tree. it is the "package", the "thing" we are storing. in this case that thing is a string like "Gators". it also includes the key information. a 2 piece thing.
//something about a cross reference cycling problem. need to include 'Class Node'
class Node;
class Item
{
public:
    string key_value;
    string info_value;
    Node *next;
    Item();
//    Item(string key, string value)
//    {
//        key_value = key;
//        info_value = value;
//    };
    string key();
    string info();
};

#endif /* defined(__Project2__item__) */

