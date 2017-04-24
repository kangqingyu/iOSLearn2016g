#include <iostream>
using namespace std;
typedef struct ListNode {
   struct ListNode *next;
    int value;
}ListNode;
void displayList(ListNode *pHead) {
    ListNode *pMove = pHead;
    while(pMove) {
    cout << pMove -> value << " ";
    pMove = pMove -> next;
    }
    cout << endl;
}
ListNode *createList(ListNode *pHead, int multiply, int length) {
    ListNode *pMove = pHead;
    pMove -> value = 30;
    while(--length) {
    ListNode *newNode = new ListNode();
    newNode -> value = length * multiply ;
    pMove -> next = newNode;
    pMove = pMove -> next;
    }
    return pHead;
}
ListNode * mergeSortedList(ListNode *p1Head, ListNode *p2Head) {
    ListNode *pMove1 = p1Head;
    ListNode *pMove2 = p2Head;
    ListNode *pMergerHead;
    if(p1Head == NULL) return p2Head;
    if(p2Head == NULL) return p1Head;
/*
    if (pMove1 -> value > pMove2 -> value ) {
        pMergerHead = p1Head;
	pMergerHead -> next = mergeSortedList(p1Head -> next, p2Head);
     
    } else{
	     pMergerHead = p2Head;
             pMergerHead -> next = mergeSortedList(p2Head -> next, p1Head);
    }
    return pMergerHead;
*/
    if (pMove1 -> value > pMove2 -> value ) {
        pMergerHead = p1Head;
	p1Head -> next = mergeSortedList(p1Head -> next, p2Head);
        return p1Head;
    } else{
	     pMergerHead = p2Head;
             p2Head -> next = mergeSortedList(p2Head -> next, p1Head);
    }
    return p2Head;

}
int main() {
    ListNode *p1 = new ListNode();
    ListNode *p2 = new ListNode();
    p1 = createList(p1, 3, 5);
    p2 = createList(p2, 2, 9);
    displayList(p1);
    displayList(p2);
    p1 = mergeSortedList(p1, p2);
    displayList(p1);
    return 0;
}
