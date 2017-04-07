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
        int valueR = root -> value;
        std::cout << valueR << "  " ;
        preOrderTree(root -> lChild);
        preOrderTree(root -> rChild);
    }
}
BitTreeNode *conConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder) {
    //根结点
    int rootValue = startPreorder[0];
    BitTreeNode *root = new BitTreeNode( );
    root -> value = rootValue;
    root -> lChild = NULL;
    root -> rChild = NULL;
    if (startPreorder == endPreorder) {
        if (startPreorder == endPreorder && *startPreorder ==* startInorder) {
            return root;
        }
    }
    int *rootInorder  = startInorder;
    while (rootInorder <= endInorder && *rootInorder != *startPreorder) {
        ++rootInorder;
    } //rootInder就指向了中序遍历的根
    int leftLength = rootInorder - startInorder;
    //找到 子、前序 的
    //构造左
    if (leftLength > 0) {
        root -> lChild =  conConstructCore(startPreorder + 1, startPreorder + leftLength  , startInorder, rootInorder - 1);
    }
    //right tree
    if (endPreorder - startPreorder > leftLength) {
       root -> rChild =    conConstructCore(startPreorder + leftLength + 1, endPreorder, rootInorder + 1, endInorder);
    }
    return root;
}
BitTreeNode * ConstructTree(int *preorder, int *inorder, int length) {
    if (length < 1 || preorder == NULL || inorder == NULL) {
        return NULL;
    } else {
        return conConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
    }
}

int main(int argc, const char * argv[]) {
    
    BitTreeNode *root ;
    int a1[9] = {1,2,4 ,7, 3, 5, 6, 8};
    int a2[9] = {4, 7, 2, 1, 5, 3, 8, 6};
//    root =   createBitTree();
    root =   ConstructTree(a1 , a2 , 8);
    preOrderTree(root);
    return 0;
}
