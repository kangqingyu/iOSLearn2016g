#include <iostream>
typedef struct BitTreeNode{
    char value;
    struct BitTreeNode *lChild;
    struct BitTreeNode *rChild;
}BitTreeNode;

BitTreeNode *  createTree() {
    char tempValue;
    scanf("%c", &tempValue);
    if(tempValue == '#') {
    return NULL;
    } else {
    BitTreeNode *newNode = new BitTreeNode();
    newNode -> value = tempValue;
    newNode -> lChild = createTree();
    newNode -> rChild = createTree();     
    return newNode;
    }
}
void preOrderTree(BitTreeNode *root) {
    if(root == NULL) {
        return ;
    } 
    std::cout << root -> value << "  ";
    preOrderTree(root -> lChild); 
    preOrderTree(root -> rChild);
}

int main(/*int argc, const * argv[]*/) {
    BitTreeNode *root = createTree();
    std::cout << std::endl;
    preOrderTree(root);
    return 0;
}
    
