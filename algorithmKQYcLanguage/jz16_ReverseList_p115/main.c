//
//  main.c
//  jz16_ReverseList_p114
//
//  Created by kqy on 20/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//
// 按答案的方法：在while内生成pNext。因为pnode可能指向最后一个节点。
//p114之所以错，或说与这个不同的地方，就是没有解决第一个指针的指向问题。

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
    NodeList currentP;
    NodeList reverseP;
    currentP = pHead;
    preP = NULL;
    while (currentP != NULL ) {
        NodeList nextP;
        nextP =  currentP -> next;
        if (nextP  == NULL ) {
            reverseP = currentP;
        }
        currentP->next = preP;
        preP = currentP;
        currentP = nextP;
    }
    return reverseP;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    NodeList *pHead = (NodeList)malloc(sizeof(LNode));
    pHead = createListAuto(pHead, 5);
    displayList(pHead);
    
    printf("after reverse:\n");
    NodeList readP = (NodeList) malloc(sizeof(LNode));
    readP = reverseList(pHead);
    displayList(readP);
    return 0;
}
