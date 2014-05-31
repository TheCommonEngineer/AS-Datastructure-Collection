//
//  ASLinkedList.h
//  ASCollection
//
//  Created by Abhilash Sahu on 05/05/14.
//  Copyright (c) 2014 AS Programs. All rights reserved.
//

#ifndef __ASCollection__ASLinkedList__
#define __ASCollection__ASLinkedList__

#include <iostream>


#pragma mark - Structures

template <typename T>
struct Node {
    T data;
    Node *next;
};

template <typename T>
struct SingleNode : Node<T> {

};

template <typename T>
struct DoubleNode : Node<T>{
    DoubleNode *prev;
};

#pragma mark - Classes

template <typename T>
class ASLinkedList {
    
protected:
    unsigned _nodeCount;

public:
    ASLinkedList();
    
    virtual bool addNodeAtFirst(T data) = 0;
    virtual bool addNodeAtLast(T data) = 0;
    virtual bool addNodeAfter(Node<T> *node, T data) = 0;
    
    virtual void deleteFirstNode() = 0;
    virtual void deleteLastNode() = 0;
    virtual void deleteNodeAfter(Node<T> *node) = 0;
    virtual void deleteNode(Node<T> *node) = 0;
    
    virtual Node<T>* searchNodeWithData(T data) = 0;
    virtual Node<T>* firstNode() = 0;
    virtual Node<T>* lastNode() = 0;

    virtual void printList() = 0;
    virtual void reverseList() = 0;
    virtual void emptyList() = 0;
    
    unsigned nodeCount();
};

template <typename T>
class ASSinglyLinkedList : public ASLinkedList<T> {
    SingleNode<T> *head;
    
    SingleNode<T> *createNodeWithData(T data);
    
public:
    ASSinglyLinkedList();
    ~ASSinglyLinkedList();

    bool addNodeAtFirst(T data);
    bool addNodeAtLast(T data);
    bool addNodeAfter(Node<T> *node, T data);

    void deleteFirstNode();
    void deleteLastNode();
    void deleteNodeAfter(Node<T> *node);
    void deleteNode(Node<T> *node);

    Node<T>* searchNodeWithData(T data);
    Node<T>* firstNode();
    Node<T>* lastNode();
    
    void printList();
    void reverseList();
    void emptyList();
};

template <typename T>
class ASDoublyLinkedList : public ASLinkedList<T> {
    DoubleNode<T> *head;
    DoubleNode<T> *tail;

    DoubleNode<T> *createNodeWithData(T data);
public:
    ASDoublyLinkedList();
    ~ASDoublyLinkedList();
    bool addNodeAtFirst(T data);
    bool addNodeAtLast(T data);
    bool addNodeAfter(Node<T> *node, T data);
    
    void deleteFirstNode();
    void deleteLastNode();
    void deleteNodeAfter(Node<T> *node);
    void deleteNode(Node<T> *node);
    
    Node<T>* searchNodeWithData(T data);
    Node<T>* firstNode();
    Node<T>* lastNode();

    void printList();
    void reverseList();
    void emptyList();
    
};

#include "ASLinkedList.cpp"     //For template class compilation

#endif /* defined(__ASCollection__ASLinkedList__) */
