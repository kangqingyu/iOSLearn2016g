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
//4.25再写一次(7).
BitTreeNode *reConstructTree03(int *preStartOrder, int *preEnd, int *inStartOrder, int *inEnd) {
    BitTreeNode *root = new BitTreeNode();
    root -> value = preStartOrder[0];
    root -> lChild = NULL;
    root -> rChild = NULL;
    if (preStartOrder == preEnd ) {
//        if (*preStartOrder == *inStartOrder && *preEnd && *inEnd) {
        if (inStartOrder == inEnd && *preStartOrder == *inStartOrder) {
            return root;
        }
        return NULL;
    }
    
     int *inRoot = inStartOrder ;
    while (*inRoot != *preStartOrder && inRoot < inEnd)  ++ inRoot;
    int leftLength = inRoot - inStartOrder;
    int * preLeftEnd = preStartOrder + leftLength;
    if (leftLength > 0) {
        root -> lChild = reConstructTree03(preStartOrder + 1, preLeftEnd, inStartOrder, inRoot -1);
    }
//    if (leftLength < inEnd - inRoot) {
    if (leftLength < preEnd - preStartOrder) {
        root -> rChild = reConstructTree03(preStartOrder + leftLength + 1, preEnd, inRoot + 1, inEnd);
    }
    return root;
}
BitTreeNode *createTree03(int *array1, int *array2, int length) {
    if (length <1 ) {
        return NULL;
    }
    return reConstructTree03(array1 , array1 + length - 1 , array2, array2 + length -1);
}
int main(int argc, const char * argv[]) {
    int  array1[9] = {1, 2, 4, 7, 3, 5, 6, 8};
    int array2[9] = {4, 7, 2, 1, 5, 3, 8, 6};// answer: 1 2 4 7 3 5 6 8
    
//    int array1[6] = {1, 2, 3, 4, 5};
//    int array2[6] = {2, 3, 1, 5, 4};
    BitTreeNode *root ;
   root = createTree03(array1, array2, 8);
    backOrderTree(root);
    std::cout << std::endl;
    preOrderTree(root);
    return 0;
}

//#if 1
//BitTreeNode * createTree02(int *preOrder, int *inOrder, int length) {
//    if (length < 1) {
//        return NULL;
//    }
//    return reConstructTree(preOrder, preOrder + length -1, inOrder, inOrder + length -1);
//}
//BitTreeNode *reConstructTree01(int *preStart, int * preEnd, int *inStart, int *inEnd) {
//    int leftLength = 0;
//    BitTreeNode *rootNode = new BitTreeNode( );
//    int rootValue = preStart[0];
//    rootNode -> value = rootValue;
//    rootNode -> lChild = NULL;
//    rootNode -> rChild = NULL;
//    
//    if (preStart == inStart) {
//        if (preStart == preEnd && *preEnd == *inEnd) {
//            return  rootNode;
//        }
//    }//  递归结束
//    
//    int *inRoot = inStart; // 中序 中的 首根结点.
//    while (*inRoot != *preStart) {
//        ++leftLength;
//        ++ inRoot;
//    }
//    int rightLength = preEnd - preStart - leftLength ;
//    int *leftPreEnd = preStart + leftLength ;
//    if (leftLength > 0) {
//        rootNode -> lChild = reConstructTree(preStart + 1, preStart + leftLength , inStart, inStart + leftLength -1);
//    }
//    if (leftLength < preEnd - preStart) {
//        rootNode -> rChild = reConstructTree(preStart + leftLength + 1, preEnd, inStart + leftLength + 1, inEnd);
//    }
//    return rootNode;
//}
//BitTreeNode * reConstructTree02(int *preStart, int *preEnd, int *inStart, int *inEnd) {
//    int rootValue = preStart[0];
//    BitTreeNode *root = new BitTreeNode( );
//    root -> value = rootValue;
//    if (preStart == preEnd) {
//        if (*preStart == *inStart) {
//            *preEnd == * inEnd;
//            return root;
//        }
//        else return NULL;
//    }
//    int *inRoot = inStart;
//    while (*inRoot != *preStart) {
//        ++inRoot;
//    }
//    int leftLength  = inRoot - inStart;
//    int *startLeftEnd = leftLength + preStart;
//    if (leftLength > 0) {
//        root -> lChild = reConstructTree(preStart + 1, startLeftEnd, inStart, inRoot - 1);
//    }
//#warning  leftLength< 这个如何计算？
//    //  < endPre - startPre.
//    if (leftLength < inEnd - inRoot) {
//        root -> rChild = reConstructTree(startLeftEnd + 1, preEnd, inRoot + 1, inEnd);
//    }
//    return root;
//}
//#endif
