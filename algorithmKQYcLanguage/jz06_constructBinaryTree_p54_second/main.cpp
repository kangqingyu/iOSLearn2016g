//
//  main.cpp
//  jz06_constructBinaryTree_p54_second
//
//  Created by kqy on 12/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
BitTreeNode *reConstructTree(int *preStart, int * preEnd, int *inStart, int *inEnd) ;
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
        int valueR = root -> value;
        std::cout << valueR << "  " ;
        preOrderTree(root -> lChild);
        preOrderTree(root -> rChild);
    }
}
BitTreeNode * createTree(int *preOrder, int *inOrder, int length) {
    if (length < 1) {
        return NULL;
    }
    return reConstructTree(preOrder, preOrder + length -1, inOrder, inOrder + length -1);
}
BitTreeNode *reConstructTree(int *preStart, int * preEnd, int *inStart, int *inEnd) {
    int leftLength = 0;
    int *pMove = preStart;
    while (*pMove != *inStart) {
        ++leftLength;
        ++ pMove;
    }
     BitTreeNode *rootNode = new BitTreeNode( );
    rootNode -> value = *inStart;
    rootNode -> lChild = reConstructTree(preStart, preStart + leftLength, <#int *inStart#>, <#int *inEnd#>)

    if (preStart == preEnd && preStart == inStart) {
        return  ;
    }//  递归结束
    
}
int main(int argc, const char * argv[]) {
    
    return 0;
}
