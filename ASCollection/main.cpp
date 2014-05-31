//
//  main.cpp
//  ASCollection
//
//  Created by Abhilash Sahu on 05/05/14.
//  Copyright (c) 2014 AS Programs. All rights reserved.
//

#include <iostream>
#include "ASBinaryTree.h"
#include "ASQueue.h"

using namespace std;

#pragma mark - Test Cases

void testSiglyLinkedList() {
    cout<<"\n\n Testing Singly Linked List...\n\n";

    ASSinglyLinkedList<int> *SLL = new ASSinglyLinkedList<int>();
    for (int i = 0; i < 10; i++) {
        SLL->addNodeAtLast(i);
    }
    SLL->printList();
    SLL->reverseList();
    SLL->printList();
    
    SLL->addNodeAtFirst(-1);
    SLL->addNodeAtLast(10);
    SLL->addNodeAfter(SLL->searchNodeWithData(5), 100);
    SLL->printList();
    
    SLL->deleteFirstNode();
    SLL->deleteLastNode();
    SLL->deleteNodeAfter(SLL->searchNodeWithData(5));
    SLL->deleteNode(SLL->searchNodeWithData(2));
    SLL->printList();
    
    delete SLL;
}

void testDoublyLinketList() {
    cout<<"\n\n Testing Doubly Linked List...\n\n";
    
    ASDoublyLinkedList<int> *DLL = new ASDoublyLinkedList<int>();
    for (int i = 0; i < 10; i++) {
        DLL->addNodeAtLast(i);
    }
    DLL->printList();
    DLL->reverseList();
    DLL->printList();
    
    
    DLL->addNodeAtFirst(-1);
    DLL->addNodeAtLast(10);
    DLL->addNodeAfter(DLL->searchNodeWithData(5), 100);
    DLL->printList();
    
    DLL->deleteFirstNode();
    DLL->deleteLastNode();
    DLL->deleteNodeAfter(DLL->searchNodeWithData(5));
    DLL->deleteNode(DLL->searchNodeWithData(2));
    DLL->printList();
    
    delete DLL;
}

void testQueue() {
    cout<<"\n\n Testing Queue...\n\n";

    ASQueue<int> *queue = new ASQueue<int>();
    for (int i = 0; i<10; i++) {
        queue->pushRear(i);
    }
    for (int i = 0; i<10; i++) {
        cout<<queue->popFront()<<" ";
    }

    delete queue;
}
void testBinaryTree() {
    cout<<"\n\nTesting Binary Tree...\n\n";

    ASBinaryTree<int> *BT = new ASBinaryTree<int>();
    for (int i = 0; i < 10; i++) {
        BT->insertNode(i);
    }
    BTNode<int>* searchedNode = BT->searchNode(5);
    if (searchedNode)
        cout<<"\n Node found at ("<<searchedNode<<") containing data ["<<searchedNode->data<<"]\n";
    else
        cout<<"\n Node not found\n";
    BT->inorderPrint();
    BT->preorderPrint();
    BT->postorderPrint();
    
    BT->deleteNode();
    BT->deleteNode();
    BT->deleteNode();
    BT->inorderPrint();
    
    delete BT;
}


#pragma mark - main()
int main(int argc, const char * argv[])
{
    testSiglyLinkedList();
    testDoublyLinketList();
    testQueue();
    testBinaryTree();
    
    return 0;
}

