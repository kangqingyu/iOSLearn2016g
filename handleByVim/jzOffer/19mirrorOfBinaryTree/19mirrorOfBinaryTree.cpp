#include <iostream>
#include <stack>
using namespace std;

typedef struct BitTreeNode{
    char value;
    struct BitTreeNode *lChild;
    struct BitTreeNode *rChild;
}BitTreeNode;   
BitTreeNode * createTree(BitTreeNode *rootNode) {
    BitTreeNode *node = new BitTreeNode();  
    char temp;
    scanf("%c", &temp); 
    node -> value = temp;
    if (temp != '#') {
    node -> lChild = createTree(node);
    node -> rChild = createTree(node);
    } else return NULL;
    return node;
}
void displayTree(BitTreeNode *root) {
    if (root) {
    cout << root -> value;
    displayTree(root -> lChild);
    displayTree(root -> rChild);
    }
}
void mirrorTree(BitTreeNode *root) {
    if (!root) return;  
    BitTreeNode *tempNode;  
    tempNode = root -> lChild;
    root -> lChild = root -> rChild;
    root -> rChild = tempNode;
    if (root -> lChild) mirrorTree(root -> lChild);
    if (root -> rChild) mirrorTree(root -> rChild);
} 
int main(int argc, const char *argv[]) {
    BitTreeNode *root = createTree(root);
    displayTree(root);
    cout << endl;
    mirrorTree(root);
    displayTree(root);
    cout << endl;
    return 0;
}
