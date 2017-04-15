#include <iostream>
typedef struct ListNode {
    struct ListNode *next;
    int value;
}ListNode;
ListNode * createList( ) {
    ListNode *headNode = new ListNode(); 
    ListNode *pMove = headNode;
    int length = 5;
    while(--length) {
    ListNode *newNode = new ListNode();
    newNode -> value = length;
    pMove -> next = newNode;
    newNode -> next = NULL;
    pMove = pMove -> next;
    }
    return headNode;
}
void displayList(ListNode *pHead, int length) {
    ListNode *pMove = pHead;
    for (int i = 0; i < length; ++i) {
        std::cout << pMove -> value << "   ";
        pMove = pMove -> next;
    }
}
void reverseList(ListNode *pHead) {
  //different from  pHead -> next != NULL
    if(!pHead -> next) {
        reverseList(pHead -> next) ;
    } 
    std::cout << pHead -> value << " ";
}
int main(int argc, const char *argv[]) {
    ListNode *pHead = createList();
    displayList(pHead, 5);
    std::cout << std::endl;
    reverseList(pHead);
    return 0;
}
