//
//  main.cpp
//  jz16_ReverseList_p113Second
//
//  Created by kqy on 27/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
#include <stack>
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
    LNode *p = pHead;
    for (int i = 0; i < length; ++i) {
        std::cout << p -> value << "  ";
        p = p->next;
    }
    std::cout<< std::endl;
}
LNode* reverseList(LNode *pHead) {
    LNode *pFront = pHead;
    LNode *pBack = pHead;
    LNode *pMove = pHead;
    pFront = pFront -> next -> next;
    pMove = pMove -> next;
    while (pMove -> next) {
        pMove ->next =pBack;
        pBack = pMove;
        pMove =pFront;
        pFront = pFront -> next;
    }
    pMove = pBack;
    return pMove;
}
void reverListUseStack(LNode *pHead) {
    stack <LNode *> nodes;
    LNode *p = pHead;
    while (p) {
        nodes.push(p);
        p = p-> next;
    }
    while (!nodes.empty()) {
//        cout << nodes.top() << "  ";
        pHead = nodes.top();
        cout << pHead -> value << " ";
        nodes.pop();
    }
}
int main(int argc, const char * argv[]) {
    LNode *pHead;
    createListAuto(&pHead, 6);
    displayList(pHead, 6);
//    pHead = reverseList(pHead);
//    displayList(pHead, 6);
    reverListUseStack(pHead);
    return 0;
}
