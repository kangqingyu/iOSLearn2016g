//
//  main.cpp
//  jz23_PrintTreeFromTopToBottom_p137
//
//  Created by kqy on 10/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
#include <deque>
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
        char valueR = root -> value;
        std::cout << valueR << "  " ;
        preOrderTree(root -> lChild);
        preOrderTree(root -> rChild);
    }
}


void printTreeFromTopToBottom(BitTreeNode *treeRoot) {
    if (treeRoot == NULL) {
        return ;
    }
    deque<BitTreeNode *> treeDeque;
    treeDeque.push_back(treeRoot );
    cout << "level" <<  endl;
    while (treeDeque.size()  ) {
//        cout <<treeDeque.front() -> value;
//        treeDeque.pop_front();
        BitTreeNode *pNode = treeDeque.front();
        cout << pNode -> value << " ";
        treeDeque.pop_front();
        if (pNode -> lChild)  treeDeque.push_back(pNode -> lChild);
        if (pNode -> rChild)  treeDeque.push_back(pNode -> rChild);

    }// while
    cout << endl;
}//
int main(int argc, const char * argv[]) {
    BitTreeNode *tree = createBitTree();
    preOrderTree(tree);
    printTreeFromTopToBottom(tree);
    return 0;
}
