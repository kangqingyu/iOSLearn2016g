//
//  main.cpp
//  jz28_stringPermutation
//
//  Created by kqy on 02/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
int countNumber(char *strHead, int length) {
    if (length == 1) {
        return 1;
    } else {
        char *strP = strHead;
        ++strP;
        return 2 + countNumber(strP, length -1);
    }
}
int countNumber(char *strHead, int length, int start) {
    if (length == 1) {
        return 1;
    } else {
        char *strP = strHead;
        ++strP;
        return 2 + countNumber(strP, length -1);
    }
}
int main(int argc, const char * argv[]) {
    
    char testStr[100] = "helloWorld";
    int length = strlen(testStr);
    std::cout << countNumber(testStr, length) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
