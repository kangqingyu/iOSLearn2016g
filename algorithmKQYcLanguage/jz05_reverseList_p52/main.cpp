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
}ListNode, *List;
void reverseList(ListNode *pHead) {
//    stack_t <ListNode *> nodes;
    stack<ListNode *> nodes;
    ListNode *pNode = pHead;
    while (pNode!= NULL ) {
        nodes.push(pNode);
        pNode = pNode->next;
    }
    while (!nodes.empty()) {
        nodes.po78+9
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
