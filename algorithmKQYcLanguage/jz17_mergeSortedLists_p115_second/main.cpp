//
//  main.cpp
//  jz17_mergeSortedLists_p115_second
//
//  Created by kqy on 07/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct  LNode {
    int value;
    struct LNode * next;
}LNode;
void createListAuto1(LNode **pHead, int length) {
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
        newNode ->value =  i * 2 + 3;
        newNode -> next = NULL;
        p -> next  = newNode;
        p = newNode;
    }
    p -> next = NULL;
}

void createListAuto2(LNode **pHead, int length) {
    if (length < 1) {
        return;
    } else if (*pHead ==NULL) {
        LNode *headNode = new LNode();
        headNode -> value = 888;
        headNode ->next = NULL;
        *pHead = headNode;
    }
    LNode *p = new LNode();
    p = *pHead;
    for (int i = 0; i < length; ++ i ) {
        LNode *newNode = new LNode();
        newNode ->value =  (i+1) * 4;
        newNode -> next = NULL;
        p -> next  = newNode;
        p = newNode;
    }
    p -> next = NULL;
    
}
LNode * mergerList(LNode *p1, LNode *p2) {
    if (p1 == NULL && p2 == NULL ) {
        return NULL;  
    }
    if (p1 == NULL ) {
        return p2;
    } else if (p2 == NULL) {
        return p1;
    }
//    LNode *pa = p1;
//    LNode *pb = p2;
//    if (p1 -> value < p2 -> value) {
//        pa = pa -> next;
//        p1 -> next = mergerList(pa , p2);
//        return p1;
//
//    } else if (p1 -> value < p2 -> value ) {
//        pb = pb -> next;
//        p2 -> next = mergerList(p1 ,pb);
//        return p2;
//    }
    LNode *pMerge;
    if (p1 -> value < p2 -> value) {
        pMerge = p1;
        pMerge -> next = mergerList(p1 -> next, p2);
    } else {
        pMerge = p2;
        pMerge ->next = mergerList(p1, p2 -> next);
    }
    return pMerge;
}
void displayList(LNode *pHead, int length) {
    if (pHead == NULL || pHead -> next == NULL ) {
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
void test01myself() {
    LNode *pHead1 = new LNode();
    LNode *pHead2 = new LNode();
    LNode *pMergeList = new LNode( );
    createListAuto1(&pHead1, 3);
    createListAuto2(&pHead2, 3);
    displayList(pHead1, 4);
    displayList(pHead2, 4);
    mergerList(pHead1 , pHead2);
//    mergeList(pHead1, 4,  pHead2 , 4, pMergeList);
    displayList(pHead1, 7);
}

int main() {
    test01myself();
}
