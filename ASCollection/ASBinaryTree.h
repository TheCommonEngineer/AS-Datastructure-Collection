//
//  ASBinaryTree.h
//  ASCollection
//
//  Created by Abhilash Sahu on 07/05/14.
//  Copyright (c) 2014 AS Programs. All rights reserved.
//

#ifndef __ASCollection__ASBinaryTree__
#define __ASCollection__ASBinaryTree__

#include <iostream>
#include <iomanip>

template <typename T>
struct BTNode {
    T data;
    BTNode *left;
    BTNode *right;
};

template <typename T>
class ASBinaryTree {
    BTNode<T> *root;
    unsigned _nodeCount;

    BTNode<T>* createNode(T data);
public:
    ASBinaryTree();
    ~ASBinaryTree();
    
    bool insertNode(T data);    //Level order insertion
    void deleteNode();          //Level order deletion
    void emptyTree();
    
    BTNode<T>* searchNode(T data);
    unsigned nodeCount();
    
    void inorderPrint();
    void preorderPrint();
    void postorderPrint();
};


#include "ASBinaryTree.cpp"     //For template class compilation

#endif /* defined(__ASCollection__ASBinaryTree__) */
