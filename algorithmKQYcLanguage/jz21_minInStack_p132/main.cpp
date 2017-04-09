//
//  main.cpp
//  jz21_minInStack_p132
//
//  Created by kqy on 09/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;
template <typename T> class  StackWithMin {
public:
    StackWithMin(void);
    ~StackWithMin(void);
    void  push(const T& value);
    void pop();
    const T& min() const;  /// (void) const ??
private:
    stack<T> m_min;
    stack<T> m_data;
};
template <typename T> StackWithMin<T>:: StackWithMin(void) {}
template <typename T> StackWithMin<T>:: ~StackWithMin(void){}
template <typename T> void StackWithMin<T>:: push(const T&value){
//    assert(m_data.size > 0 && m_min.size > 0);
    m_data.push(value);
#warning 还要考虑没有元素的时候
    if (value < m_min.top() || m_min.size() == 0) {
        m_min.push(value);
    } else {
        m_min.push(m_min.top());
    }
}
template <typename T> void StackWithMin<T>::pop() {
    assert(m_data.size > 0 && m_min.size > 0);
    m_data.pop();
    m_min.pop();
}
template <typename T> const T& StackWithMin<T>::min() const {
    assert(m_min.size() > 0 && m_data.size() > 0);
//    T getValue = m_min.top();
//    m_min.pop(); ///一行就可以解决。。。
//    return getVaelue;
    return m_min.top();
}
int main(int argc, const char * argv[]) {
    StackWithMin<int>  KqyStack;
    KqyStack.push(5);
    KqyStack.push(3);
    KqyStack.push(7);
    cout << KqyStack.min() << endl;
    return 0;
}
