//
//  main.cpp
//  jz37_FirstCommonNodesInList_second
//
//  Created by kqy on 06/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct  LNode {
    int value;
    struct LNode * next;
}LNode, ListNode;
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
        if (!p) {
            break;
        }
        std::cout << p -> value << "  ";
        p = p->next;
    }
    std::cout<< std::endl;
}
int lengthOfList(ListNode *pHead1) {
    int length = 0;
    ListNode *pMove = pHead1;
    while (pMove) {
        ++length;
        pMove = pMove -> next;
    }
    return length;
}
ListNode *commonHeadList(ListNode *pHead1, ListNode *pHead2) {
    int length1 = lengthOfList(pHead1);
    int length2 = lengthOfList(pHead2);
    int distance = length1 - length2;
    ListNode *pLong = pHead1;
    ListNode *pShort = pHead2;
    if (length1 < length2) {
        pLong = pHead2;
        pShort = pHead1;
        distance = - distance;
    }
    while (distance --) {
        pLong = pLong -> next;
    }
    while (pLong -> value != pShort -> value && pLong != NULL) {
        pLong = pLong -> next;
        pShort = pShort -> next;
    }
    return pLong;
}
int main(int argc, const char * argv[]) {
    ListNode * p1 = new ListNode();
    p1 -> value = 3;
    createListAuto(&p1, 5);
    displayList(p1, 6);
    ListNode * p2 = new ListNode();
    p2 -> value = 6;
    createListAuto(&p2, 5);
    displayList(p2, 6);
    
    ListNode *pCommon = commonHeadList(p1, p2);
    displayList(pCommon, 6);
    return 0;
}
