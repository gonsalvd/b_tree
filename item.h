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
using namespace std;

#endif /* defined(__Project2__item__) */


//an item is what we are storing in our array in the b-tree. it is the "package", the "thing" we are storing. in this case that thing is a string like "Gators". it also includes the key information. a 2 piece thing.
class Item
{
private:
    string key_value;
    string info_value;
public:
    Item();
    string key();
    string info();
};
