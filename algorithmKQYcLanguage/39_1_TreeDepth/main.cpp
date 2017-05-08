//
//  main.cpp
//  31_1_TreeDepth
//
//  Created by kqy on 08/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct BitTreeNode {
    char value;
    struct BitTreeNode * lChild;
    struct BitTreeNode *rChild;
}BitTreeNode;
BitTreeNode * createTree01() {
    BitTreeNode *root1, *root2, *root2Left, *root3Right ;
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
    return root2;
}
BitTreeNode * createTree02() {
    BitTreeNode *root1, *root2, *root2Left, *root3Right ;
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
    return root2;
}
int deepOfTree(BitTreeNode *root) {
    if (!root) {
        return 0;
    }
    int left = deepOfTree(root -> lChild);
    int right = deepOfTree(root -> rChild);
    return left > right ? (left + 1) : (right + 1);
}
int main(int argc, const char * argv[]) {
    BitTreeNode * t1 = createTree01();
    cout << deepOfTree(t1);
    return 0;
}
