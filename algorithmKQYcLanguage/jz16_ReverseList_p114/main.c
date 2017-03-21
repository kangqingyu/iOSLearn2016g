//
//  main.c
//  jz16_ReverseList_p114
//
//  Created by kqy on 20/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//我做的，在 while外生成 next结点，但是答案是在内生成。因为pnode可能指向最后一个节点。
// wrong!!! 思路不清晰！！！
#include <stdio.h>
typedef struct LNode {
    int value;
    struct LNode *next;
}LNode, *NodeList;
NodeList createListAuto(NodeList pHead, int count) {
    NodeList pRear = pHead;
    for (int i = 0; i < count; ++i) {
        NodeList pNode = (NodeList) malloc(sizeof(LNode));
        pNode -> value = i + 1;
        pRear ->next = pNode;
        pRear = pNode;
    }
    pRear -> next = NULL;
    return pHead;
}
void displayList(NodeList pHead) {
    NodeList p = pHead;
    while (p->next) {
        printf("%d  ", p->value);
        p = p->next;
    }
    printf("%d\n", p->value);
}
NodeList reverseList(NodeList pHead) {
    NodeList preP;
    NodeList nextP;
    NodeList currentP;
    NodeList reverseP;
    currentP = pHead;
    nextP =  currentP -> next;
    preP = NULL;
    while (nextP ->next) {
//        nextP = currentP  -> next;
       
//        preP = currentP;//
//        preP = nextP;
        preP = currentP;
        currentP = nextP;
        nextP = nextP -> next;
        currentP -> next = preP;

        if (nextP->next == NULL ) {
            reverseP = nextP;
        }
    }
    return reverseP;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    NodeList *pHead = (NodeList)malloc(sizeof(LNode));
    pHead = createListAuto(pHead, 5);
    displayList(pHead);
    
    printf("after reverse\n");
    NodeList readP = (NodeList) malloc(sizeof(LNode));
    readP = reverseList(pHead);
    displayList(readP);
    return 0;
}
