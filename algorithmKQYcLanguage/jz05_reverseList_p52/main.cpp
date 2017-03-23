//
//  main.cpp
//  jz05_reverseList_p52
//
//  Created by kqy on 22/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
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

void reverseList(ListNode *pHead) {
//    stack_t <ListNode *> nodes;
    stack<ListNode *> nodes;
    ListNode *pNode = pHead;
    while (pNode!= NULL ) {
        nodes.push(pNode);
        pNode = pNode->next;
    }
    while (!nodes.empty()) {
        pNode = nodes.top();
        printf("%d\t", pNode->value);
        nodes.pop();
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode *  pHead = new ListNode();
    pHead = createListAuto(pHead, 5);
    displayList(pHead);
    reverseList(pHead);
//    displayList(pHead);

    return 0;
}
