#include <iostream>
#include <stack>
using namespace std;
template <typename T> class CQueue {
public:
    CQueue();
    ~CQueue();  
    void pushNumber(const T& number);  
    T popNumber(void);
private:
    stack<int > stack1;
    stack<int > stack2;
};
template <typename T> CQueue<T>::CQueue(){}
template <typename T> CQueue<T>::~CQueue(){}
template <typename T> void CQueue<T>::pushNumber(const T& number) {
    stack1.push(number);
}
template <typename T> T  CQueue<T>::popNumber(void) {
    T temp;
    while(stack2.size()<=0) {
	while(stack1.size()>0) {
	    temp = stack1.top();
	    stack2.push(temp);
	    stack1.pop();
	}
    }
    if(stack2.size() == 0) return -1;
    temp = stack2.top();
    stack2.pop();
    return temp;
}
int main(int argc, const char * argv[]) {
    CQueue<int> myQueue;
    myQueue.pushNumber(10);
    myQueue.pushNumber(11);
    cout << myQueue.popNumber();
    myQueue.pushNumber(2);
    myQueue.pushNumber(3);
    myQueue.pushNumber(4);
    cout << myQueue.popNumber();
    myQueue.pushNumber(5);
    cout << myQueue.popNumber();
    return 0;
}
