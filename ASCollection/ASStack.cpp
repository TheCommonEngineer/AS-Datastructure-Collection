//
//  ASStack.cpp
//  ASCollection
//
//  Created by Abhilash Sahu on 10/05/14.
//  Copyright (c) 2014 AS Programs. All rights reserved.
//

#ifndef __ASCollection__ASStack__cpp
#define __ASCollection__ASStack__cpp

#include "ASStack.h"

template <typename T>
ASStack<T>::ASStack() {
    linkedList = new ASSinglyLinkedList<T>();
}

template <typename T>
ASStack<T>::~ASStack<T>() {
    delete linkedList;
    linkedList = nullptr;
}

template <typename T>
T ASStack<T>::top() {
    return linkedList->firstNode();
}

template <typename T>
bool ASStack<T>::hasData() {
    return dataCount();
}

template <typename T>
unsigned ASStack<T>::dataCount() {
    return linkedList->nodeCount();
}

template <typename T>
bool ASStack<T>::push(T data) {
    return linkedList->addNodeAtFirst(data);
}

template <typename T>
T ASStack<T>::pop() {
    Node<T>* topNode = linkedList->firstNode();
    T data = topNode->data;
    linkedList->deleteFirstNode();
    return data;
}


#endif /* defined(__ASCollection__ASStack__cpp) */
