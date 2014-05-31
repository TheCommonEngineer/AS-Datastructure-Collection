//
//  ASStack.h
//  ASCollection
//
//  Created by Abhilash Sahu on 10/05/14.
//  Copyright (c) 2014 AS Programs. All rights reserved.
//

#ifndef __ASCollection__ASStack__
#define __ASCollection__ASStack__

#include <iostream>
#include "ASLinkedList.h"

template <typename T>
class ASStack {
    ASSinglyLinkedList<T>* linkedList;
    
public:
    ASStack();
    ~ASStack();
    
    T top();
    
    bool hasData();
    unsigned dataCount();
    
    bool push(T data);
    T pop();
    
    
};

#include "ASStack.cpp"     //For template class compilation

#endif /* defined(__ASCollection__ASStack__) */
