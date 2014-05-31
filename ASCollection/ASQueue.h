//
//  ASQueue.h
//  ASCollection
//
//  Created by Abhilash Sahu on 07/05/14.
//  Copyright (c) 2014 AS Programs. All rights reserved.
//

#ifndef __ASCollection__ASQueue__
#define __ASCollection__ASQueue__

#include <iostream>
#include "ASLinkedList.h"


template <typename T>
class ASQueue {
    ASDoublyLinkedList<T> *linkedList;
    
public:
    ASQueue();
    ~ASQueue();
    
    T front();
    T rear();
    
    bool hasData();
    unsigned dataCount();
    
    bool pushRear(T data);
    T popFront();
    
};


#include "ASQueue.cpp"     //For template class compilation

#endif /* defined(__ASCollection__ASQueue__) */
