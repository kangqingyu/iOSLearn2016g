//
//  main.cpp
//  jz15_KthNodeFromEnd_p110Second
//
//  Created by kqy on 26/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//  这里才发现如同p50 ** 的问题。我以前写的自动创建，遍历链表的操作，全都没有空指针的情况。下边测试用一个**。

#include <iostream>
using namespace std;
typedef struct LNode {
    int value;
    struct LNode *next;
}LNode ;
void createListAuto(LNode *pHead, int length) {  //当为空指针时会出错
    if (length < 1) {
        return ;
    }
    LNode *p = new LNode( );
    p = pHead;

//    p ->next  = NULL; // 这样会出错，因为开始p为空。
    for (int i = 0; i < length; ++i ) {
        LNode *newNode = new LNode();
        newNode -> value = i *2;
        newNode -> next = NULL;
        p  -> next = newNode;
        p = newNode;
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
    // insert code here...
    std::cout << "Hello, World!\n";
    LNode *phead = new LNode();
    createListAuto(phead, 5);
    displayList(phead, 5);
    coutBackKNumber(phead, 2);
    return 0;
}
