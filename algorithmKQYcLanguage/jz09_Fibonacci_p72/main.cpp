//
//  main.cpp
//  jz09_Fibonacci_p72
//
//  Created by kqy on 24/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
int fibonacciReverse(int border) {
    if (border < 1) {
        return 0;
    } else if(border == 1  || border == 2) {
        return 1;
    } else {
        return (fibonacciReverse(border - 1) + fibonacciReverse((border - 2)));
    }
}
int FibonacciFor(int border) {
    int front = 1;
    int back = 1;
    int result = 0;
    if (border < 3) {  
        return border < 1 ?  0 : 1;
    }
    for (int i = 2 ; i < border; ++i) {
        result = front + back;
        back = front;
        front = result;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<< fibonacciReverse(4) << endl;
    cout << FibonacciFor(6) << endl;
    return 0;
}
