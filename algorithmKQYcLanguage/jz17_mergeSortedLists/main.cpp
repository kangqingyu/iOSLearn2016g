//
//  main.cpp
//  jz17_mergeSortedLists
//
//  Created by kqy on 31/03/2017.
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
        newNode ->value =  i * 2 + 2;
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
        newNode ->value =  (i+1) * 6;
        newNode -> next = NULL;
        p -> next  = newNode;
        p = newNode;
    }
    p -> next = NULL;

}
void displayList2(LNode *pHead, int length) {
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
void mergeList(LNode *list1, int length1, LNode *list2, int length2, LNode *list3) {
    LNode *p1 = list1 -> next;
    LNode *p2 = list2 -> next;
    LNode *pMove = list3;
    while (p1 -> next && p2 -> next) {
        if (p1 -> value < p2 -> value) {
            pMove ->next = p1;
            pMove = p1;
            p1 = p1 -> next;
        } else if(p1 -> value > p2 ->value) {
            pMove -> next = p2;
            pMove = p2;
            p2 = p2 -> next;
        } else {
            pMove -> next = p1;
            pMove = p1;
            pMove -> next = p2;
            pMove = p2;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
    }// while1
    while (p1 != NULL ) {
        pMove -> next = p1;
        pMove = p1;
        p1 = p1 -> next;
    }
    while (p2 ) {
        pMove -> next = p2;
        pMove  = p2;
        p2 = p2 -> next;
    }
    pMove -> next = NULL;
}
LNode* mergeList02(LNode *pHead1,   LNode *pHead2 ) {
    if (pHead1 == NULL ) {
        return pHead2;
    }
    if (pHead2 == NULL ) {
        return pHead1   ;
    }
    LNode *nodeList = NULL;
    if (pHead1 -> value < pHead2 -> value) {
        nodeList = pHead1;
        nodeList -> next = mergeList02(pHead1 -> next, pHead2 );
    } else if (pHead1 -> value > pHead2 -> value) {
        nodeList = pHead2;
        nodeList -> next = mergeList02(pHead1, pHead2 -> next);
    }  else {
//        pHead2 = pHead2 -> next;
        nodeList = pHead1;
          nodeList -> next = mergeList02(pHead1 -> next, pHead2 -> next);
        // equal
    }
    return nodeList;
}
void test02 () {
    LNode *pHead1 = new LNode();
    LNode *pHead2 = new LNode();
    createListAuto1(&pHead1, 3);
    createListAuto2(&pHead2, 3);
    displayList2(pHead1, 4);
    displayList2(pHead2, 4);
    pHead1 = mergeList02(pHead1, pHead2);
    displayList2(pHead1, 6);
}
int main(int argc, const char * argv[]) {
    test02();
    return 0;
}
void test01myself() {
    LNode *pHead1 = new LNode();
    LNode *pHead2 = new LNode();
    LNode *pMergeList = new LNode( );
    createListAuto1(&pHead1, 3);
    createListAuto2(&pHead2, 3);
    displayList2(pHead1, 4);
    displayList2(pHead2, 4);
    mergeList(pHead1, 4,  pHead2 , 4, pMergeList);
    displayList2(pMergeList, 7);
}
