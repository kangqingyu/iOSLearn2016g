//
//  main.cpp
//  jz09_Fibonacci_p72Second
//
//  Created by kqy on 01/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
int fibonacci(unsigned int target) {
    int backArray[2] = {0, 1};
    if (target < 2) {
        return backArray[target];
    }
    int firstNumber = 0, i;
    int secondNumber = 1;
    double result = 0;
    for (i = 2; i <= target; ++i ) {
        result = firstNumber + secondNumber;
        firstNumber = secondNumber;
        secondNumber = result;
    }
    
    return result;
}
int main(int argc, const char * argv[]) {
    cout << fibonacci(6) << std::endl;
    return 0;
}
