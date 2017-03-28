//
//  main.cpp
//  jz04_ReplaceBlank_p45Second
//
//  Created by kqy on 28/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>

void replaceBlank(char *strHead) {
    char *pOld = strHead;
    char *pNew = strHead;
    int blankCount  = 0;
    while (*pOld) {
        if (*pOld == ' ') {
            ++blankCount;
        }
        ++pOld;
        ++pNew;
    }
    int MoveTemp = blankCount * 2;
    while (MoveTemp--) {
        ++pNew;
    }
    while (pOld != strHead) {
        if (*pOld != ' ') {
            *pNew = *pOld;
            --pNew;
            -- pOld;
        } else {
            --pOld;
            *pNew = '0';
            --pNew;
            *pNew = '2';
            --pNew;
            *pNew = '%';
            --pNew;
        }
    }
    *pNew = *strHead;
}
int main(int argc, const char * argv[]) {
    char str01[100] = "   hello world we are happy";
    replaceBlank(str01);
    std::cout << str01 << std::endl;
    return 0;
}
