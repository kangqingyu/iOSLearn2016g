//
//  main.cpp
//  jz18_subStructInTree_p118_second
//
//  Created by kqy on 17/04/2017.
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
bool isSameTree(BitTreeNode *rootA, BitTreeNode *rootB) ;
bool isSubTree(BitTreeNode *ARoot, BitTreeNode *BRoot) {
    bool result = false;
    if (ARoot != NULL && ARoot != NULL) {
        if (ARoot -> value = BRoot ->value) {
            result = isSameTree(ARoot, BRoot);
        }
        if (!result) {
            isSubTree(ARoot -> lChild, BRoot );
        }
        if (!result) {
            isSubTree(ARoot -> rChild, BRoot);
        }
    }
    return  result;
}
bool isSameTree(BitTreeNode *rootA, BitTreeNode *rootB) {
    bool result = false;
    if (rootB == NULL) {
        return  true;
    }
    if (rootA == NULL) {
        return false;
    }
    if (rootA -> value != rootB -> value) {
        return false;
    }
    return isSameTree(rootA -> lChild, rootB -> lChild) && isSameTree(rootA -> rChild, rootB -> rChild);
}
int main(int argc, const char * argv[]) {
    BitTreeNode *root1, *root2, *root2Left, *root3Right ;
    root1 =   createBitTree();
    root2 =  new BitTreeNode();
    root2Left = new BitTreeNode();
    root3Right = new BitTreeNode();
    //    生成一个树999 - 1 -2
    root2 -> value = '9';
    root2Left ->value = '1';
    root3Right ->value = '2';
    root2 ->lChild = root2Left;
    root2 -> rChild = root3Right;
    root2Left ->lChild = NULL;
    root2Left ->rChild = NULL;
    root3Right ->lChild = NULL;
    root3Right -> rChild = NULL;
    cout << "input finish  ." << endl;
    bool resultB = isSubTree(root1, root2);
    cout << "result: " << resultB << endl;

    return 0;
}

bool isSubTree0417(BitTreeNode *rootA, BitTreeNode *rootB) {
    bool result = false;
    if (rootA != NULL && rootB != NULL ) {
        if (rootA -> value == rootB -> value) {
            result = isSameTree(rootA, rootB);
        }
        if (!result) {
            result  = isSubTree(rootA -> lChild, rootB);
        }
        if (!result) {
            result  = isSubTree(rootA -> rChild, rootB);
        }
    }
    return result;
}
bool isSameTree0417(BitTreeNode *rootA, BitTreeNode *rootB) {
    if (rootB == NULL ) {
        return true;
    }
    if (rootA == NULL&& rootB != NULL ) {
        return false;
    }
    if (rootA -> value != rootB -> value) return  false;
    return isSameTree(rootA -> lChild, rootB -> lChild) && isSameTree(rootA -> rChild, rootB -> rChild);
}

