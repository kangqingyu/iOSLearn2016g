#include <iostream>
typedef struct ListNode{
   struct ListNode *next;
   int value;
}ListNode;
void DeleteNode(ListNode **pHead, ListNode *pToBeDeleted) {
    if( !pHead || !pToBeDeleted) return;   
    if(pToBeDeleted -> next != NULL) {
    ListNode *pNext = pToBeDeleted -> next;
    pToBeDeleted -> value = pNext -> value;
    pToBeDeleted -> next = pNext -> next;
    delete pNext;
    pNext = NULL;
    } else if(*pHead == pToBeDeleted) {
    delete pToBeDeleted;
    pToBeDeleted = NULL;
    } else {
    ListNode *pMove = *pHead;
    while(pMove -> next != pToBeDeleted) pMove = pMove -> next;
    pMove -> next = NULL;
    delete pToBeDeleted;
    pToBeDeleted = NULL;
    }
}
ListNode * createList() {
    ListNode *pHead = new ListNode();
    pHead -> value = 99;
    ListNode *pMove = pHead;
    for (int i = 0; i < 5; ++ i) {
        ListNode *newNode = new ListNode();
        newNode -> value = (1 + i) * 2;
        pMove -> next = newNode;
        pMove = pMove -> next;
    }
    return pHead;
}
void display(ListNode *pHead) {
    ListNode *pMove = pHead;
    while(pMove) {
    std::cout << pMove -> value << " ";
    pMove = pMove -> next;
    }
    std::cout << std::endl;
}
int main(int argc, const char * argv[]) {
    ListNode *pHead = createList();
    ListNode *pDelete = pHead -> next -> next;
    display(pHead);
    DeleteNode(&pHead, pDelete);
    display(pHead);
    return 0;
}
