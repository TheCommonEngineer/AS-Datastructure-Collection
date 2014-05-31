//
//  ASQueue.cpp
//  ASCollection
//
//  Created by Abhilash Sahu on 07/05/14.
//  Copyright (c) 2014 AS Programs. All rights reserved.
//

#ifndef __ASCollection__ASQueue__cpp
#define __ASCollection__ASQueue__cpp

#include "ASQueue.h"

template <typename T>
ASQueue<T>::ASQueue() {
    linkedList = new ASDoublyLinkedList<T>();
}

template <typename T>
ASQueue<T>::~ASQueue() {
    delete linkedList;
    linkedList = nullptr;
}

template <typename T>
T ASQueue<T>::front() {
    DoubleNode<T>* front = (DoubleNode<T>*)linkedList->firstNode();
    int data = -1;
    if (front) {
        data = front->data;
    }
    return data;
}

template <typename T>
T ASQueue<T>::rear() {
    DoubleNode<T>* rear = (DoubleNode<T>*)linkedList->lastNode();
    int data = -1;
    if (rear) {
        data = rear->data;
    }
    return data;
}

template <typename T>
bool ASQueue<T>::hasData() {
    return dataCount();
}

template <typename T>
unsigned ASQueue<T>::dataCount() {
    return linkedList->nodeCount();
}

template <typename T>
bool ASQueue<T>::pushRear(T data) {
    return linkedList->addNodeAtLast(data);
}

template <typename T>
T ASQueue<T>::popFront() {
    int data = front();
    linkedList->deleteFirstNode();
    return data;
}


#endif /* defined(__ASCollection__ASQueue__cpp) */
