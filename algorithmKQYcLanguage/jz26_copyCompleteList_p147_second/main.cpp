//
//  main.cpp
//  jz26_copyCompleteList_p147_second
//
//  Created by kqy on 08/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct ListNode {
    int value;
    struct ListNode *next;
    struct ListNode *sibling;
}ListNode;
void autoCreateComplictList(ListNode *pHead, int length) {
    ListNode *pMove = pHead;
    for (int i = 0; i < length ; ++i) {
        ListNode *newNode = new ListNode( );
        pMove ->next = newNode;
        pMove = pMove -> next;
        pMove -> value = (i +1)  ;
        pMove ->sibling = NULL;
    }
    ListNode *pTest1 = pHead;
    ListNode *pTest2 = pHead -> next;
    ListNode *pTest3 = pHead -> next -> next;
    ListNode *pTest4 = pHead -> next -> next -> next;
    pTest2 -> sibling = pTest4;
    pTest3 ->  sibling = pHead;
    pTest4 ->sibling = pTest3;
 
}
void copy2List(ListNode *pHead) {
    ListNode *pMove = pHead;
    while ( pMove) {
        ListNode *addNode = new ListNode( );
        addNode -> next = pMove -> next;
        addNode -> value = pMove -> value;
        pMove -> next = addNode;
        pMove = addNode -> next;
    }
//    return pHead;
}
void copySiblingP(ListNode *pHead) {
    ListNode *pMove = pHead;
    ListNode *pCopyMove = pHead -> next;
    while (pMove ) {  //如何用while( pMove)来解决。可能后面的还有。 52行加上判断？
        if (pMove ->sibling) {
            pCopyMove -> sibling = pMove ->sibling -> next;
        }
        pMove = pCopyMove -> next;
        if (pCopyMove -> next) {
            pCopyMove = pMove -> next;
        }
    }
//    return pHead;
}
ListNode * divoceLongList(ListNode *pHead) {
    ListNode *pMove = pHead;
    ListNode *pCopyMove = pHead -> next;
    ListNode *pCopyHeadP = pHead; // 返回这个，记录，其实不用这么麻烦。。用pHead->next就可以了。
    while (pCopyMove -> next) {
        pMove -> next = pCopyMove -> next;
        pMove = pMove -> next;
        pCopyMove -> next = pMove -> next;
        pCopyMove = pCopyMove -> next;
    }
    return pCopyHeadP;
}
ListNode * copyComplictList(ListNode *pHead) {
    copy2List(pHead);
    copySiblingP(pHead);
    pHead = divoceLongList(pHead);
    return pHead;
}
int main(int argc, const char * argv[]) {
    ListNode *pHead = new ListNode( );
    autoCreateComplictList(pHead, 8);
    pHead = copyComplictList(pHead);
    ListNode *pMove = pHead;  
    while (pMove) {
        int nextValue = pMove -> next ? pMove -> next -> value : 0000;
        cout << pMove -> value  << " next " << nextValue  << "-----";
        if (pMove -> sibling) {
            cout << "sibling:" << pMove -> sibling -> value  ;
        }
        cout << endl;
        pMove = pMove -> next;
    }
    return 0;
}
