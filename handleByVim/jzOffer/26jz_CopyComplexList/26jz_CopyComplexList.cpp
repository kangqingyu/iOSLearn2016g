//2017.4.24
//有问题，在creaList xcode中写成功了。对应26vim.cpp.	
//
//#include <iostream>
using namespace std;
typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *siblNext;
    int value;
}ListNode;   
void copyTwoList(ListNode *pHead) {
    ListNode *pMove = pHead;
    while(pMove) {
    ListNode *newNode = new ListNode();       
    newNode -> value = pMove -> value;
    newNode -> next = pMove -> next;
    pMove -> next = newNode;
    pMove = newNode -> next;
    }
    //处理了pHead,并不用 返回吧。return  pHead;
}
void copySiblList(ListNode *pHead) {
    ListNode *pMove = pHead;
    ListNode *pCopy = pHead -> next;
    while(pMove) {
        pCopy -> siblNext = pMove -> siblNext -> next;
        pMove = pCopy -> next;
	pCopy = pMove -> next;
    }
}
ListNode *diviceList(ListNode *pHead) {
    ListNode *pMove = pHead -> next -> next;
    ListNode *pCopyMove = pHead -> next;
    ListNode *pCopyHead = pCopyMove; 
    while(pMove) {
	pCopyMove -> next  = pMove -> next;
        pCopyMove = pMove -> next;
	pMove -> next = pCopyMove -> next;
	pMove = pCopyMove -> next;
    }
    return pCopyHead;
}
ListNode * createList(ListNode *pHead ) {
    int length = 5;
    ListNode *pMove = pHead;
    while(--length) {
    ListNode *newNode = new ListNode();  
    newNode -> value = (10 - length);
    pMove ->next = newNode;
    pMove ->next -> siblNext = pMove;
    pMove = pMove -> next;  
    }
    return pHead;
}
void displayList(ListNode *pHead) {
    ListNode *pMove = pHead;
    if(pMove) {
    cout << pMove -> value << "  " ;
    if(pMove -> siblNext) cout << pMove -> siblNext -> value << " sib  ";
    cout << endl;
    pMove = pMove -> next;
    }
}
int main() {
    ListNode *p = createList(p);
    displayList(p);
    return 0;
}
