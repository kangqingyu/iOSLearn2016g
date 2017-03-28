//
//  main.cpp
//  jz13_DeleteNodeInList
//
//  Created by kqy on 28/03/2017.
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
void deleteNode(LNode **pHeader, LNode *pToBeDeleted) {
    if (pHeader == NULL ) {
        return ;
    } else if (  pToBeDeleted == NULL ) {
        cout << "to be deleted is null" << endl;
        return;
    }
    //1 有多个结点的链表          删除的非尾结点
    if (pToBeDeleted -> next) {
        LNode *pNext = pToBeDeleted -> next;
        pToBeDeleted -> value = pNext -> value;
        pToBeDeleted ->next = pNext -> next;
        delete pNext;
        pNext  = NULL;
    } else if(*pHeader == pToBeDeleted) {
        *pHeader = NULL;
        return;
    } else {
        LNode *pMove = *pHeader;
        while (pMove ->next != pToBeDeleted) {
            ++pMove;
        }
        pMove -> next = NULL;
    }
    
}

void test1() {
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
    deleteNode(&pHead, deleteNode6);
    displayList(pHead, 6);
}
void testNull() {
    LNode *pHead = new LNode();
    pHead -> value = 9;
    LNode *deleteNode0 = new LNode( );
    deleteNode0 =     pHead  ;
    deleteNode(&pHead, deleteNode0);
    displayList(pHead, 1);
}
int main(int argc, const char * argv[]) {
    testNull();
    return 0;
}
