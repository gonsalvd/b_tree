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
#include "Item.h"

class Node
{
public:
    int m;
    int *b;
    Node(int size)
    {
        m=0;
        b=new int[size];
    }
};

#endif /* defined(__Project2__node__) */