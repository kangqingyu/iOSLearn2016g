//
//  main.cpp
//  jz21_minInStack_p132_second
//
//  Created by kqy on 18/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;
template <typename T> class CQueue {
public:
    CQueue(void);
    ~CQueue(void);
    T& minNumber(void);
    void pushNumber(const T& value);
    void popNumber(void);
private:
    stack <T> minStack;
    stack <T> kStack;
};
template <typename T> CQueue<T>::CQueue(void){}
template <typename T> CQueue<T>::~CQueue(void){}
template <typename T> T& CQueue<T>::  minNumber(void){
    assert(minStack.size() > 0 && kStack.size() >0);
//    if (minStack.size()) {
//        int tempMin  = minStack.top();
//        minStack.pop();
//        return tempMin;
//    }
//    return -1;
    return minStack.top();

}
template <typename T> void CQueue<T>::pushNumber(const T& value) {
    if (kStack.size() == 0) {
        kStack.push(value);
        minStack.push(value);
        return ;
    }
    if (value < minStack.top()) {
        minStack.push(value);
    } else {
        int tempMin = minStack.top();
        minStack.push(tempMin);
    }
    kStack.push(value);
}
template <typename T> void CQueue<T>::popNumber(void) {
    if (kStack.size() < 1) {
        return  ;
    } else {
        minStack.pop();
        kStack.pop();
    }
}
int main(int argc, const char * argv[]) {
    CQueue<int> kQueue;
    kQueue.pushNumber(8);
    cout << kQueue.minNumber() << endl;
    kQueue.pushNumber(3);
    cout << kQueue.minNumber() << endl;
    kQueue.pushNumber(9);
    cout << kQueue.minNumber() << endl;
    kQueue.pushNumber(2);
    cout << kQueue.minNumber() << endl;
    kQueue.popNumber() ;
    cout << kQueue.minNumber() << endl;

    return 0;
}
