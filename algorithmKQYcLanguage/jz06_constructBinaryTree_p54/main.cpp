//
//  main.cpp
//  jz06_constructBinaryTree_p54
//
//  Created by kqy on 06/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
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
        std::cout << root -> value << "  " ;
        preOrderTree(root -> lChild);
        preOrderTree(root -> rChild);
    }
}
BitTreeNode *conConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder) {
    //根结点
    int rootValue = startPreorder[0];
    BitTreeNode *root = new BitTreeNode( );
    
}
BitTreeNode * ConstructTree(int *preorder, int *inorder, int length) {
    if (length < 1 || preorder == NULL || inorder == NULL) {
        return NULL;
    } else {
        return conConstructCore(preorder, preorder + length - 1, preorder, preorder + length - 1);
    }
}

int main(int argc, const char * argv[]) {
    
    BitTreeNode *root ;
    root =   createBitTree();
    preOrderTree(root);
    return 0;
}
