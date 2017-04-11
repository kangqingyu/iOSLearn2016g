#include <iostream>
using namespace std;
typedef struct ListNode{
    int value;
    struct ListNode * next;
}ListNode;
ListNode * createListAuto(ListNode **pHead, int length) {
    ListNode *headNode = new ListNode();
    headNode -> value = 9;
    headNode -> next = NULL;
    *pHead = headNode;
    ListNode *pMove = *pHead;
    for (int i = 0; i < length; ++i) {
    ListNode *newNode = new ListNode(); 
    newNode -> value = i + 1;
    pMove -> next = newNode;
    newNode -> next = NULL;
    pMove = pMove -> next;
    }
    return *pHead;
}
int coutKthNodeFromEnd(ListNode *pHead, int k) {
    ListNode *pFront = pHead;
    ListNode *pBack = pHead;
    while(k--) pFront = pFront -> next;
    while(pFront ) {
    pFront = pFront -> next;
    pBack = pBack -> next;
    }
    int valueB = pBack -> value;
//    cout << *pBack -> value << endl;
    return valueB;
}
    
void displayList(ListNode **pHead) {
    if (!*pHead) {
    return ;
    }  
    ListNode *pMove = *pHead;
    while (pMove) {
    cout << pMove -> value << "  ";
    pMove = pMove -> next;
    }
    cout << endl;
}
    
int main(int argc, const char *argv[]) {
    ListNode *pNew ;
    pNew = createListAuto(&pNew, 6);
    displayList(&pNew);
    cout << "number: " << coutKthNodeFromEnd(pNew, 5) << endl;
    return 0;
}
