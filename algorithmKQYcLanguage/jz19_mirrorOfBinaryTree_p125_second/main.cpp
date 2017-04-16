//
//  main.cpp
//  jz19_mirrorOfBinaryTree_p125_second
//
//  Created by kqy on 15/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
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
void mirrorTree(BitTreeNode *root) {
    if (root == NULL ) {
        return;
    }
    BitTreeNode *tempRoot  = new BitTreeNode( );
    tempRoot = root -> lChild;
    root -> lChild = root -> rChild;
    root -> rChild = tempRoot;
}
int main(int argc, const char * argv[]) {
    BitTreeNode *root;
    root = createBitTree();
    cout << endl;
    preOrderTree(root);
    std::cout << "start change " << std::endl;
    mirrorTree(root);
    preOrderTree(root);
    return 0;
}
