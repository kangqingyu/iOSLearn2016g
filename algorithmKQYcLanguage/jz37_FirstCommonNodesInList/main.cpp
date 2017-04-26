//
//  main.cpp
//  jz37_FirstCommonNodesInList
//
//  Created by kqy on 26/04/2017.
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
ListNode * commonPHead(ListNode *pHead1, ListNode *pHead2) {
    int length1 = 0, length2 = 0;
    ListNode *pMove1, * pMove2;
    pMove1 = pHead1;
    pMove2 = pHead2;
    while (pMove1)  {
        pMove1 = pMove1 -> next;
        ++length1;
    }
    while (pMove2) {
        pMove2 = pMove2 -> next;
        ++length2;
    }
    int longerLength = length1 - length2;
    ListNode *pFirst, *pSecond  ;
    if (longerLength > 0) {
        pFirst = pHead1;
        pSecond = pHead2;
        while (longerLength--) {
            pFirst = pFirst -> next;
        }
    } else {
        pFirst = pHead2;
        pSecond = pHead1;
        while (longerLength--) {
            pFirst = pFirst -> next;
        }
    }
    while (pFirst-> value != pSecond -> value) {
        pFirst = pFirst -> next;
        pSecond = pSecond -> next;
    }
    return pFirst;
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
    
    ListNode *pCommon = commonPHead(p1, p2);
    displayList(pCommon, 6);
    return 0;
}
