//
//  main.cpp
//  jz05_reverseList_p52Second
//
//  Created by kqy on 31/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
#include <stack>
typedef struct ListNode {
    int value;
    struct ListNode *next;
}ListNode, *NodeList;
NodeList createListAuto(NodeList pHead, int count) {
    NodeList pRear = pHead;
    for (int i = 0; i < count; ++i) {
        NodeList pNode = (NodeList) malloc(sizeof(ListNode));
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
void reverseList01(ListNode * pHead) {
    std::stack <ListNode *> nodes;
    ListNode *pNode = pHead;
    while (pNode ->next) {
        nodes.push(pNode);
        pNode = pNode ->next;
    }
    while (!nodes.empty()) {
        ListNode *LNode  = nodes.top();
        std::cout << LNode -> value << " ";
//        std::cout << nodes.top() << "  ";
        nodes.pop();
    }
    std::cout << std::endl;
}
void reverse02(ListNode *pHead) {
    if (pHead->next) {
        reverse02(pHead->next);
    }
    std::cout << pHead-> value << "   ";
}
int main(int argc, const char * argv[]) {
    ListNode *  pHead = new ListNode();
    pHead = createListAuto(pHead, 5);
    displayList(pHead);
    reverse02(pHead);

    return 0;
}
