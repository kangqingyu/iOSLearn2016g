//
//  main.cpp
//  jz13_DeleteNodeInList_p99 second
//
//  Created by kqy on 04/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct  LNode {
    int value;
    struct LNode * next;
}LNode;
void createListAuto(LNode **pHead, int length) {
    if (length < 1) {
        return;
    } else if (*pHead ==NULL) {
        LNode *headNode = new LNode();
        headNode -> value = 999;
        headNode ->next = NULL;
        *pHead = headNode;
    }
    LNode *p = new LNode();
    p = *pHead;
    for (int i = 0; i < length; ++ i ) {
        LNode *newNode = new LNode();
        newNode ->value =  (i+1) * 3;
        newNode -> next = NULL;
        p -> next  = newNode;
        p = newNode;
    }
}
void displayList(LNode *pHead, int length) {
    if (pHead == NULL ) {
        cout<< "can't cout null" <<endl;
        return;
    }
    LNode *p = pHead;
    
    for (int i = 0; i < length; ++i) {
        std::cout << p -> value << "  ";
        p = p->next;
    }
    std::cout<< std::endl;
}
void deleteNodeInList(LNode **pHead, LNode *deletedNode) {
    if (!*pHead || !deletedNode) {
        return;
    }
    if (deletedNode -> next != NULL) {
        deletedNode -> value = deletedNode -> next -> value;
        LNode *pDelete = deletedNode -> next;
        deletedNode -> next = pDelete  -> next;
        pDelete = NULL;
        delete pDelete;
    } else if (deletedNode == *pHead) {//只有一个头结点
        *pHead = NULL;
    } else {
        LNode *pMove = *pHead;
        while (pMove -> next != deletedNode) {
            pMove = pMove -> next;
        }
        pMove -> next = NULL;
        deletedNode = NULL;
        delete deletedNode;
    }
}
int main(int argc, const char * argv[]) {
    LNode *pHead;
    createListAuto(&pHead, 7);
    displayList(pHead, 7);
    
    LNode *deleteNode0 = new LNode( );
    deleteNode0 =     pHead  ;
    LNode *deleteNode1 = new LNode( );
    deleteNode1 =     pHead -> next;
    LNode *deleteNode2 = new LNode( );
    deleteNode2 = deleteNode1 -> next;
    LNode *deleteNode3 = new LNode( );
    deleteNode3 =     deleteNode2 -> next;
    LNode *deleteNode4 = new LNode( );
    deleteNode4 = deleteNode3 -> next;
    LNode *deleteNode5 = new LNode( );
    deleteNode5 =     deleteNode4 -> next;
    LNode *deleteNode6 = new LNode( );
    deleteNode6 = deleteNode5 -> next;
    deleteNodeInList(&pHead, deleteNode5);
    displayList(pHead, 6);
    return 0;
}
