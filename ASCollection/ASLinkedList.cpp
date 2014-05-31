//
//  ASLinkedList.cpp
//  ASCollection
//
//  Created by Abhilash Sahu on 05/05/14.
//  Copyright (c) 2014 AS Programs. All rights reserved.
//

#ifndef __ASCollection__ASLinkedList__cpp
#define __ASCollection__ASLinkedList__cpp

#include "ASLinkedList.h"

using namespace std;

#pragma mark - Parent Linked List

template <typename T>
ASLinkedList<T>::ASLinkedList(){
    _nodeCount = 0;
}

template <typename T>
unsigned ASLinkedList<T>::nodeCount() {
    return _nodeCount;
}

#pragma mark - Singly Linked List

template <typename T>
ASSinglyLinkedList<T>::ASSinglyLinkedList() {
    head = nullptr;
}

template <typename T>
ASSinglyLinkedList<T>::~ASSinglyLinkedList() {
    emptyList();
    head = nullptr;
}

template <typename T>
SingleNode<T>* ASSinglyLinkedList<T>::createNodeWithData(T data){
    SingleNode<T> *newNode = new SingleNode<T>();
    if (newNode) {
        newNode->data = data;
        this->_nodeCount++;        //or can be used as ASLinkedList<T>::_nodeCount++;
    }
    return newNode;
}

template <typename T>
bool ASSinglyLinkedList<T>::addNodeAtFirst(T data) {
    bool success = false;
    if (SingleNode<T> *newNode = createNodeWithData(data)) {
        newNode->next = head;
        head = newNode;
        success = true;
    }
    return success;
}

template <typename T>
bool ASSinglyLinkedList<T>::addNodeAtLast(T data) {
    bool success = false;
    if (!head) {
        return addNodeAtFirst(data);
    }
    if (SingleNode<T> *newNode = createNodeWithData(data)) {
        SingleNode<T> *ptr = head;
        while (ptr->next)
            ptr = (SingleNode<T>*)ptr->next;
        ptr->next = newNode;
    }
    return success;
}

template <typename T>
bool ASSinglyLinkedList<T>::addNodeAfter(Node<T> *node, T data) {
    bool success = false;
    if (node) {
        if (SingleNode<T> *newNode = createNodeWithData(data)) {
            newNode->next = node->next;
            node->next = newNode;
            success = true;
        }
    }
    return success;
}

template <typename T>
void ASSinglyLinkedList<T>::deleteFirstNode() {
    if (head) {
        SingleNode<T> *p = head;
        head = (SingleNode<T>*)head->next;
        delete p;
        this->_nodeCount--;
    }
}

template <typename T>
void ASSinglyLinkedList<T>::deleteLastNode() {
    SingleNode<T> *p,*q = nullptr;
    p = head;
    if (p){
        q = (SingleNode<T>*)p->next;
        if (q) {
            while (q->next) {
                p = q;
                q = (SingleNode<T>*)q->next;
            }
            delete q;
            p->next = nullptr;
        }
        else {  //Single node
            delete p;
            head = nullptr;
        }
        this->_nodeCount--;
    }
}

template <typename T>
void ASSinglyLinkedList<T>::deleteNodeAfter(Node<T> *node) {
    if (node) {
        SingleNode<T> *p = (SingleNode<T>*)node->next;
        if (p) {
            node->next = p->next;
            delete p;
            this->_nodeCount--;       //We should verify whether node belongs to the list
        }
    }
}

template <typename T>
void ASSinglyLinkedList<T>::deleteNode(Node<T> *node){
    if (node) {
        SingleNode<T> *p;
        if (node->next) {
            node->data = node->next->data;          // For this to work, '=' should have been overloaded for T
            p = (SingleNode<T>*)node;
        }
        else {
            p = head;
            while (p && p->next != node)
                p = (SingleNode<T>*)p->next;
        }
        deleteNodeAfter(p);
    }
}

template <typename T>
Node<T>* ASSinglyLinkedList<T>::searchNodeWithData(T data) {
    SingleNode<T> *ptr = head;
    while (ptr && ptr->data != data)
        ptr = (SingleNode<T>*)ptr->next;
    return ptr;
}

template <typename T>
Node<T>* ASSinglyLinkedList<T>::firstNode() {
    return head;
}

template <typename T>
Node<T>* ASSinglyLinkedList<T>::lastNode() {
    SingleNode<T> *p = head;
    while (p && p->next) {
        p = (SingleNode<T>*)p->next;
    }
    return p;
}

template <typename T>
void ASSinglyLinkedList<T>::reverseList() {
    SingleNode<T> *p,*q,*r;
    p = head;
    q = r = nullptr;
    if (p)
        q = (SingleNode<T>*)p->next;
    while (q) {
        p->next = r;
        r = p;
        p = q;
        q = (SingleNode<T>*)q->next;
    }
    if (p)
        p->next = r;
    head = p;
}

template <typename T>
void ASSinglyLinkedList<T>::printList() {
    cout<<"HEAD  ["<<this->_nodeCount<<"]"<<endl<<"||"<<endl;
    SingleNode<T> *ptr = head;
    while (ptr) {
        cout<<ptr->data<<" ==> ";
        ptr = (SingleNode<T>*)ptr->next;
    }
    cout<<"NULL"<<endl;
}

template <typename T>
void ASSinglyLinkedList<T>::emptyList() {
    while (head) {
        deleteFirstNode();
    }
}

#pragma mark - Doubly Linked List

template <typename T>
ASDoublyLinkedList<T>::ASDoublyLinkedList() {
    head = tail = nullptr;
}

template <typename T>
ASDoublyLinkedList<T>::~ASDoublyLinkedList() {
    emptyList();
    head = tail = nullptr;
}

template <typename T>
DoubleNode<T>* ASDoublyLinkedList<T>::createNodeWithData(T data) {
    DoubleNode<T> *newNode = new DoubleNode<T>();
    if (newNode) {
        newNode->data = data;
        newNode->next = newNode->prev = nullptr;
        this->_nodeCount++;
    }
    return newNode;
}

template <typename T>
bool ASDoublyLinkedList<T>::addNodeAtFirst(T data) {
    bool success = false;
    if (DoubleNode<T> *newNode = createNodeWithData(data)) {
        if (head){
            newNode->next = head;
            head->prev = newNode;
        }
        else
            tail = newNode;
        head = newNode;
        success = true;
    }
    return success;
}

template <typename T>
bool ASDoublyLinkedList<T>::addNodeAtLast(T data) {
    bool success = false;
    if (!head) {
        return addNodeAtFirst(data);
    }
    if (DoubleNode<T> *newNode = createNodeWithData(data)) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        success = true;
    }
    return success;
}

template <typename T>
bool ASDoublyLinkedList<T>::addNodeAfter(Node<T> *node, T data) {
    bool success = false;
    if (node) {
        if (DoubleNode<T> *newNode = createNodeWithData(data)) {
            newNode->next = node->next;
            if (node->next)
                ((DoubleNode<T>*)(node->next))->prev = newNode;
            node->next = newNode;
            success = true;
        }
    }
    return success;
}

template <typename T>
void ASDoublyLinkedList<T>::deleteFirstNode() {
    if (head) {
        this->_nodeCount--;
        DoubleNode<T> *p = (DoubleNode<T>*)head->next;
        delete head;
        if (p) {
            head = p;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
    }
}

template <typename T>
void ASDoublyLinkedList<T>::deleteLastNode() {
    if (head == tail) {
        if (head) {
            delete head;
            this->_nodeCount--;
        }
        head = tail = nullptr;
    }
    else{
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        this->_nodeCount--;
        
    }
}

template <typename T>
void ASDoublyLinkedList<T>::deleteNodeAfter(Node<T> *node) {
    if (node) {
        DoubleNode<T> *p = (DoubleNode<T>*)node->next;
        if (p) {
            node->next = p->next;
            if (p->next) {
                ((DoubleNode<T>*)(p->next))->prev = (DoubleNode<T>*)node;
            }
            delete p;
            this->_nodeCount--;       //We should verify whether node belongs to the list
        }
    }
}

template <typename T>
void ASDoublyLinkedList<T>::deleteNode(Node<T> *node){
    if (node) {
        DoubleNode<T> *doubleNode = (DoubleNode<T>*)node;
        if (head == node)
            deleteFirstNode();
        else if(tail == node)
            deleteLastNode();
        else{
            if(doubleNode->prev)
                doubleNode->prev->next = doubleNode->next;
            if(doubleNode->next)
                ((DoubleNode<T>*)(doubleNode->next))->prev = doubleNode->prev;
            delete doubleNode;
            this->_nodeCount--;       //We should verify whether node belongs to the list
        }
    }
}

template <typename T>
Node<T>* ASDoublyLinkedList<T>::searchNodeWithData(T data) {
    DoubleNode<T> *ptr = head;
    while (ptr && ptr->data != data)
        ptr = (DoubleNode<T>*)ptr->next;
    return ptr;
}

template <typename T>
Node<T>* ASDoublyLinkedList<T>::firstNode() {
    return head;
}

template <typename T>
Node<T>* ASDoublyLinkedList<T>::lastNode() {
    return tail;
}

template <typename T>
void ASDoublyLinkedList<T>::reverseList() {
    DoubleNode<T> *p;
    p = head;
    while (p) {
        DoubleNode<T> *q = p->prev;
        p->prev = (DoubleNode<T>*)p->next;
        p->next = q;
        p=p->prev;
    }
    DoubleNode<T> *r = head;
    head = tail;
    tail = r;
}

template <typename T>
void ASDoublyLinkedList<T>::printList() {
    cout<<"HEAD  ["<<this->_nodeCount<<"]"<<endl<<"||"<<endl<<"NULL";
    DoubleNode<T> *ptr = head;
    while (ptr) {
        cout<<" <==> "<<ptr->data;
        if (ptr == tail)
            cout<<"(TAIL)";
        ptr = (DoubleNode<T>*)ptr->next;
    }
    if (tail)
        cout<<" <==> NULL";
    cout<<endl;
}

template <typename T>
void ASDoublyLinkedList<T>::emptyList() {
    while (head) {
        deleteFirstNode();
    }
}

#endif /* defined(__ASCollection__ASLinkedList__cpp) */
