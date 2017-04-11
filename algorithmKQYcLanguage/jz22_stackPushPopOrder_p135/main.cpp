//
//  main.cpp
//  jz22_stackPushPopOrder_p135
//
//  Created by kqy on 11/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
bool IsPopOrder(int *pPush, int *pPop, int length) {
    stack<int > tempStack;
    for (int i = length -1; i >= 0; --i) {
        if (pPop[i] != pPush[i]) {
            <#statements#>
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
