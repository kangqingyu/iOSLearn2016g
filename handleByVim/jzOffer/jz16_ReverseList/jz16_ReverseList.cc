#include <iostream>
typedef struct ListNode {
    struct ListNode * next;
    int value;
}ListNode;
void createListAuto(ListNode **pHead, int length) {//设计传入的是空链表头
    if (length < 1) {
    return ;
    }
    ListNode *newHead = new ListNode();
    newHead -> value = 99;
    *pHead = newHead;
    ListNode *pMove = *pHead;
    int i = 0;
    while (--length) {
    ListNode *addNode = new ListNode();
    addNode -> value = (++i);
    addNode -> next = NULL;
    pMove-> next  = addNode;
    pMove = pMove -> next;
    }
}
void displayList(ListNode *pHead) {
    ListNode *pMove = pHead;
    while(pMove -> next) {//用*pMove,还是不用*? 
    std::cout <<  pMove -> value << "   ";
    pMove = pMove -> next; // 有个问题，就是下一个结点可能是 null.
    }
    std::cout << pMove -> value << std::endl;
}
ListNode * reverseList(ListNode *pHead) {
    ListNode *pBack = NULL;  
    ListNode *pMove = pHead;
    ListNode *pFront = NULL;
    ListNode *pRearHead;
    while(pMove) {
        pFront = pMove -> next;         
        pMove -> next = pBack;
        if (!pFront) {
           pRearHead = pMove;
          break;
        }

        pBack = pMove;
        pMove = pFront;
    }
    return pRearHead;
}
    
int main(int arch, const char* argv[]) {
    ListNode *pHead;
    createListAuto(&pHead, 5);
    displayList(pHead) ;
    pHead = reverseList(pHead);
    displayList(pHead);   
    return 0;
}
