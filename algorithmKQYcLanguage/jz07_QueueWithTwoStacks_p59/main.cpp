//
//  main.cpp
//  jz07_QueueWithTwoStacks_p59
//
//  Created by kqy on 05/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;
template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};
template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}
template <typename T>
T  CQueue<T>::deleteHead() {
    if (stack2.size() <= 0) {
        while (!stack1.empty()) {
            T& tempValue = stack1.top();
            stack2.push(tempValue);
            stack1.pop();
        }
    }
    if (stack2.size() == 0) {
        cout << "wrong null" << endl;
    }
    T headValue = stack2.top();
    stack2.pop();
    return headValue;
    
}

template <typename T>
void  CQueue<T>::appendTail(const T& node) {
    stack1.push(node);
}

int main(int argc, const char * argv[]) {
    CQueue<char > myQueue;
    myQueue.appendTail('h');
    myQueue.appendTail('e');
    myQueue.appendTail('l');
    myQueue.appendTail('o');
    cout << "delete head: " << myQueue.deleteHead() << endl;
    cout << "delete head: " << myQueue.deleteHead() << endl;
    cout << "delete head: " << myQueue.deleteHead() << endl;

    return 0;
}
