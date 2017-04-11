//
//  main.cpp
//  jz07_QueueWithTwoStacks_p59_second
//
//  Created by kqy on 11/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
template <typename T> class :: CQueue
{
    @public:
    CQueue();
    ~CQueue();
    const T& deleteNode();
    void addNode(const T& node);
    @private:
    deque<T> deque1;
    deque<T> deque2;
}
template <typename T> 
template <typename T> void CQueue::addNode(const T& node) {
    
}
template <typename T> const T& deleteNode() {
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


