//
//  main.cpp
//  jz23_PrintTreeFromTopToBottom_p137_second
//
//  Created by kqy on 19/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
typedef struct BitTreeNode {
    char value;
    struct BitTreeNode * lChild;
    struct BitTreeNode *rChild;
}BitTreeNode;

BitTreeNode * createBitTree( ) {
    BitTreeNode *pNewNode =  NULL;
    char tempChar = 0;
    scanf("%c", &tempChar) ;
    if (tempChar == '#') {
        pNewNode = NULL;
        
    } else {
        pNewNode = new BitTreeNode[sizeof(BitTreeNode) + 1]();
        
        pNewNode -> value = tempChar;
        pNewNode -> lChild = createBitTree();
        pNewNode -> rChild = createBitTree();
    }
    return pNewNode;
}
void preOrderTree(BitTreeNode * root) {
    if (root ==NULL ) {
        return;
    } else {
        char  valueR = root -> value;
        std::cout << valueR << " ," ;
        preOrderTree(root -> lChild);
        preOrderTree(root -> rChild);
    }
}
void levelOutputTree(BitTreeNode *root) {
    deque <BitTreeNode *> myQueue;
    myQueue.push_back(root);
 
    while (myQueue.size()) {
        BitTreeNode *tempNode = myQueue.front();
        cout << tempNode -> value << " ";
        myQueue.pop_front();
        if (tempNode -> lChild) myQueue.push_back(tempNode -> lChild);
        if (tempNode -> rChild) myQueue.push_back(tempNode -> rChild);
    }
    
}
int main(int argc, const char * argv[]) {
    BitTreeNode *root;
    root = createBitTree();
    cout << endl;
    preOrderTree(root);
    std::cout << "start change levelOutputTree " << std::endl;
    levelOutputTree(root);
    return 0;
}
