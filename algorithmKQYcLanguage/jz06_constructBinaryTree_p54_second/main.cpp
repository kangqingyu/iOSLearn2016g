//
//  main.cpp
//  jz06_constructBinaryTree_p54_second
//
//  Created by kqy on 12/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
typedef struct BitTreeNode {
    char value;
    struct BitTreeNode * lChild;
    struct BitTreeNode *rChild;
}BitTreeNode;
BitTreeNode *reConstructTree(int *preStart, int * preEnd, int *inStart, int *inEnd) ;

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
void backOrderTree(BitTreeNode * root) {
    if (root ==NULL ) {
        return;
    } else {
        int valueR = root -> value;
        backOrderTree(root -> lChild);
        backOrderTree(root -> rChild);
        std::cout << valueR << "  " ;
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
    BitTreeNode *rootNode = new BitTreeNode( );
    int rootValue = preStart[0];
    rootNode -> value = rootValue;
    rootNode -> lChild = NULL;
    rootNode -> rChild = NULL;
    
    if (preStart == inStart) {
        if (preStart == preEnd && *preEnd == *inEnd) {
        return  rootNode;
        }
    }//  递归结束
    
    int *inRoot = inStart; // 中序 中的 首根结点.
    while (*inRoot != *preStart) {
        ++leftLength;
        ++ inRoot;
    }
    int rightLength = preEnd - preStart - leftLength ;
    int *leftPreEnd = preStart + leftLength ;
    if (leftLength > 0) {
    rootNode -> lChild = reConstructTree(preStart + 1, preStart + leftLength , inStart, inStart + leftLength -1);
    }
    if (leftLength < preEnd - preStart) {
    rootNode -> rChild = reConstructTree(preStart + leftLength + 1, preEnd, inStart + leftLength + 1, inEnd);
    }
    return rootNode;
}

int main(int argc, const char * argv[]) {
    int  array1[10] = {1, 2, 4, 7, 3, 5, 6, 8};
    int array2[10] = {4, 7, 2, 1, 5, 3, 8, 6};
    BitTreeNode *root ;
   root = createTree(array1, array2, 8);
    backOrderTree(root);
    return 0;
}
