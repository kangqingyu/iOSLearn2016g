//
//  main.cpp
//  jz15_KthNodeFromEnd_p110Second avoidNull
//
//  Created by kqy on 27/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct LNode {
    int value;
    struct LNode *next;
}LNode ;
void createListAuto(LNode **pHead, int length) {  //当为空指针时会出错
    if (length < 1) {
        return ;
    }

    if (*pHead == NULL ) {
        LNode *firstNode = new LNode();
        *pHead = firstNode;//    p ->next  = NULL; // 这样会出错，因为开始p为空。
        //但是空指针可以指针 其他指针？
    }
 
    LNode *pRear ; //= new LNode( );
    pRear = *pHead;

    for (int i = 0; i < length; ++i ) {
        LNode *newNode = new LNode();
        newNode -> value = (i + 1) *2;
        newNode -> next = NULL;
         pRear -> next = newNode;
        pRear = pRear -> next;
    }
    
}
void displayList(LNode *pHead, int length ){
    LNode *p = pHead;
    if (length <1 || pHead == NULL ) {
        return ;
    }
    for (int i = 0 ; i < length; ++ i ) {
        cout << p -> value << "  ";
        p = p->next;
    }
}
void coutBackKNumber(LNode *pHead, int target) {
    int move = target;
    LNode *frontP = pHead;
    LNode * backP = pHead;
    while (move--) {
        frontP = frontP -> next;
    }
    while (frontP -> next != NULL ) {
        frontP = frontP -> next;
        backP = backP  -> next;
    }
    cout << endl << backP -> value << endl;
}
int main(int argc, const char * argv[]) {
    LNode *phead = new LNode();
    createListAuto(&    phead, 5);
    displayList(phead, 5);
    coutBackKNumber(phead, 2);
    return 0;
}
