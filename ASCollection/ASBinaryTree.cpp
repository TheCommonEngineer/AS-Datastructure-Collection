//
//  ASBinaryTree.cpp
//  ASCollection
//
//  Created by Abhilash Sahu on 07/05/14.
//  Copyright (c) 2014 AS Programs. All rights reserved.
//

#ifndef __ASCollection__ASBinaryTree__cpp
#define __ASCollection__ASBinaryTree__cpp

#include "ASBinaryTree.h"
#include "ASStack.h"


using namespace std;

enum TraversalType {
    TraversalType_inorder = 0,
    TraversalType_preorder,
    TraversalType_postorder
};

template <typename T>
ASBinaryTree<T>::ASBinaryTree() {
    root = nullptr;
    _nodeCount = 0;
}

template <typename T>
ASBinaryTree<T>::~ASBinaryTree() {
    emptyTree();
}

template <typename T>
BTNode<T>* ASBinaryTree<T>::createNode(T data) {
    BTNode<T> *newNode = new BTNode<T>();
    if (newNode) {
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
    }
    return newNode;
}

template <typename T>
bool ASBinaryTree<T>::insertNode(T data) {
    bool success = false;
    if (BTNode<T> *newNode = createNode(data)) {
        success = true;
        if (root) {
            BTNode<T> *ptr = root;
            int n = _nodeCount + 1;
            
            ASStack<unsigned short int>* bits = new ASStack<unsigned short int>();
            while (n) {
                bits->push(n%2);
                n /= 2;
            }
            bits->pop();    //Discard first bit, as we are already in root;
            
            while (bits->dataCount() > 1) {
                unsigned short nextBit = bits->pop();
                if (nextBit && ptr->right)
                    ptr = ptr->right;
                else if (!nextBit && ptr->left)
                    ptr = ptr->left;
                else {
                    cout<<"ERROR: Out of bounds error!";
                    delete newNode;
                    return false;
                }
            }
            unsigned short lastBit = bits->pop();
            if (lastBit)
                ptr->right = newNode;
            else
                ptr->left = newNode;
        }
        else
            root = newNode;

        _nodeCount++;
    }
    return success;
}

template <typename T>
void ASBinaryTree<T>::deleteNode() {
    if (_nodeCount > 1) {
        BTNode<T> *ptr = root;
        int n = _nodeCount;
        
        ASStack<unsigned short int>* bits = new ASStack<unsigned short int>();
        while (n) {
            bits->push(n%2);
            n /= 2;
        }
        bits->pop();    //Discard first bit, as we are already in root;
        
        while (bits->dataCount() > 1) {
            unsigned short nextBit = bits->pop();
            if (nextBit && ptr->right)
                ptr = ptr->right;
            else if (!nextBit && ptr->left)
                ptr = ptr->left;
            else {
                cout<<"ERROR: Out of bounds error!";
                return;
            }
        }
        unsigned short lastBit = bits->pop();
        if (lastBit) {
            delete ptr->right;
            ptr->right = nullptr;
        }
        else {
            delete ptr->left;
            ptr->left = nullptr;
        }
        _nodeCount--;
    }
    else if(_nodeCount == 1) {
        delete root;
        root = nullptr;
        _nodeCount--;
    }
    
    
}

template <typename T>
void recursiveDelete(BTNode<T>* root) { //Deletion should be postorder
    if (root) {
        recursiveDelete(root->left);
        recursiveDelete(root->right);
        delete root;
        root = nullptr;
    }
}

template <typename T>
void ASBinaryTree<T>::emptyTree() {
    recursiveDelete(root);
    _nodeCount = 0;
}

template <typename T>
void recursiveSearch(BTNode<T>* root, T data, BTNode<T>** result) {
    if (root && !*result) {
        if (root->data == data) {
            *result = root;
            return;
        }
        recursiveSearch(root->left,data,result);
        recursiveSearch(root->right,data,result);
    }
}

template <typename T>
BTNode<T>* ASBinaryTree<T>::searchNode(T data) {
    BTNode<T>* result = nullptr;
    recursiveSearch(root, data, &result);
    return result;
}

template <typename T>
void recursivePrint(BTNode<T>* node, TraversalType type, unsigned indent = 0) {
    if (node) {
        switch (type) {
            case TraversalType_inorder:
                recursivePrint(node->left, type, indent+4);
                cout<<node->data<<"|\t";
                if (indent) {
                    std::cout <<setw(indent) << ' ';
                }
                cout<<node->data<<" \n";
                recursivePrint(node->right, type, indent+4);
                break;
                
            case TraversalType_preorder:
                cout<<node->data<<" ";
                recursivePrint(node->left, type);
                recursivePrint(node->right, type);
                break;
                
            case TraversalType_postorder:
                recursivePrint(node->left, type);
                recursivePrint(node->right, type);
                cout<<node->data<<" ";

                break;
                
            default:
                break;
        }
    }
}

template <typename T>
unsigned ASBinaryTree<T>::nodeCount() {
    return _nodeCount;
}

template <typename T>
void ASBinaryTree<T>::inorderPrint() {
    cout<<endl<<"Inorder traversal:\t(look top->bottom on the LHS of'|' for inorder sequence. Rest is just the visual represnetaion of the tilted mirror image of tree :) )\n";
    recursivePrint(root, TraversalType_inorder);
}

template <typename T>
void ASBinaryTree<T>::preorderPrint() {
    cout<<endl<<"Preorder traversal:\n";
    recursivePrint(root, TraversalType_preorder);
}

template <typename T>
void ASBinaryTree<T>::postorderPrint() {
    cout<<endl<<"Postorder traversal:\n";
    recursivePrint(root, TraversalType_postorder);
}



#endif /* defined(__ASCollection__ASBinaryTree__cpp) */
