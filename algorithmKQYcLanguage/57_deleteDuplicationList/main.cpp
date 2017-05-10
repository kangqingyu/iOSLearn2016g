//
//  main.cpp
//  57_deleteDuplicationList
//
//  Created by kqy on 10/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
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
        if (i % 3 == 0) {
            newNode ->value =  i * 3;
        }else   newNode ->value =  (i+1) * 3;
        newNode -> next = NULL;
        p -> next  = newNode;
        p = newNode;
    }
}
void displayList(LNode *pHead, int length) {
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
void deleteDuplication(LNode **pHead) {
    LNode *preP = *pHead;
    LNode *currentP = *pHead ;
    LNode *nextP;
    currentP = currentP -> next;
    while (currentP) {
        nextP = currentP -> next;
        if (!nextP) {
            break;
        }
        if (nextP -> value != currentP -> value) {
            preP = currentP;
            currentP = nextP;
            continue;
        }
         //else 是current = next的情况.
        while (currentP -> value == nextP -> value) {
            nextP = nextP -> next;
        }
        preP -> next = nextP;
        currentP = nextP;
    }
}
int main(int argc, const char * argv[]) {
    LNode *p1 = new LNode();
    createListAuto(&p1, 9);
    displayList(p1, 9);
    deleteDuplication(&p1);
    displayList(p1, 9);
    return 0;
}

