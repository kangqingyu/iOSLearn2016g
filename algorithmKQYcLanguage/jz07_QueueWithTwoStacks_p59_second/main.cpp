//
//  main.cpp
//  jz07_QueueWithTwoStacks_p59_second
//
//  Created by kqy on 11/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
#include <deque>
#include <stack>
#include <exception>
using namespace std;
template <typename T> class  CQueue
{
 public:
    CQueue();
    ~CQueue();
    T deleteNode();
    void addNode(const T& node);
private:
    stack<T> stack1;
    stack<T> stack2;
};
template <typename T>  CQueue<T>::CQueue (void){}
template <typename T> CQueue<T>::~CQueue (){}
template <typename T> void CQueue<T>::addNode(const T& node) {
    stack1.push(node);
}
template <typename T>   T CQueue<T>::deleteNode() {
    T tempNode;
    while (stack2.size() ==0) {
        while (stack1.size()> 0) {
            tempNode = stack1.top();
            stack2.push(tempNode);
            stack1.pop();
        }
    }
    if (stack2.size() > 0) {
        tempNode = stack2.top();
        stack2.pop();
        return tempNode;
    }else {
//        throw new exception("queue is empty");
#warning why can't use exception ?
        return tempNode;
    }
}
int main(int argc, const char * argv[]) {
    CQueue<int> kqyQueue;
    kqyQueue.addNode(5);
    kqyQueue.addNode(3);
    cout << kqyQueue.deleteNode() << endl;
    return 0;
}
