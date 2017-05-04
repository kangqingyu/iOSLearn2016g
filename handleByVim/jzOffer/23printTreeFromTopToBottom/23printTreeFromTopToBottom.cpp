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
void levelOutPutTree(BitTreeNode *root) {
    if (!root) return;
    stack<BitTreeNode *> rootStack;
    BitTreeNode *tempNode;
    rootStack.push(root);
    while(rootStack.size()) {
    tempNode = rootStack.top();
    cout << tempNode -> value;
    rootStack.pop();
    if (tempNode -> lChild) rootStack.push(tempNode -> lChild);
    if (tempNode -> rChild) rootStack.push(tempNode -> rChild);
    }
}
    
int main(int argc, const char *argv[]) {
    BitTreeNode *root = createTree(root);
    displayTree(root);
    cout << endl;
    levelOutPutTree(root);
    return 0;
}
