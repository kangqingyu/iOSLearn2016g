//
//  main.c
//  jz16_ReverseList_p113
//
//  Created by kqy on 19/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <stdio.h>
typedef struct node{
    int value;
    struct LNode  *next;
}LNode, *NodeList;
LNode * autoCreateList(LNode *lnode, int k) {
    lnode  = (LNode *) malloc(sizeof(LNode));
    //    LNode *pNode = (LNode *) malloc(sizeof(LNode));
    LNode *pNode = lnode;
    LNode *newNode;
    for (int i = 0; i < k  ; ++i) {
        newNode = (LNode *)malloc(sizeof(LNode));
        newNode ->value = 1 + i;
        pNode -> next = newNode;
        pNode = pNode->next;
    }
    pNode ->next = NULL;
    return lnode;
}
void displayList(LNode *lNode) {
    LNode *pNode = lNode;
    //    pNode = pNode -> next ;
    while (pNode ->next) {
        printf("%d  ", pNode->value);
        pNode = pNode ->next;
    }
    printf("%d  ", pNode->value);
    
}
LNode * reverseList(LNode *lnode) {
    NodeList p1node, p2node, p3node, lastNode ;
    p1node = lnode -> next;
    p2node = p1node -> next;
    p3node = p2node -> next;
    //前边的置空,lnode是头，那么他是一个指针的代表吗?
    
    p1node ->next = lnode;
    lnode->next = NULL;
    while (p3node ->next) {
        p2node ->next = p1node;
        //
        p1node = p2node;
        p2node = p3node;
        p3node = p3node -> next;
    }
    //最后的时候，p3-next =null.前边的已经好了，还有p3没有逆转。
    p3node ->next = p2node;
    p2node ->next = p1node;
    //    printf("\n%d, %d  is p2, p3", p2node ->value, p1node->value);
    lastNode  = p3node;
    return lastNode;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    LNode *listNode;
    listNode = autoCreateList(listNode, 9);
    displayList(listNode);
    LNode *lastNode =  reverseList(listNode);
    printf("\n after reverse ::\n");
    displayList(lastNode);
    printf("\n after reverse````------ \n %d\n", lastNode ->value);
    
    return 0;
}

