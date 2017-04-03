//
//  main.cpp
//  jz28_stringPermutation
//
//  Created by kqy on 02/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
int   countNumber(char *strHead, char *pStart) {
//    if (!strHead) {
//        return  0;
//    }
    int count = 0;
    if (*pStart == '\0') {
        cout << strHead << ", ";
        ++ count;
    } else {
        char *pMove = pStart;
        for ( ; *pMove != '\0' ; ++pMove) {
            char temp;
            temp = *pMove;
            *pMove = *pStart;
            *pStart = temp;
            count = 1 + countNumber(strHead, pStart + 1);
            temp = *pMove;
            *pMove = *pStart;
            *pStart = temp;
        }// for
    }
    return count;
}

int main(int argc, const char * argv[]) {
    
    char testStr[100] = "abc";
    int length = strlen(testStr);
     std::cout << countNumber(testStr, testStr) << endl;
    countNumber(testStr, testStr);
    std::cout << "Hello, World!\n";
    return 0;
}
