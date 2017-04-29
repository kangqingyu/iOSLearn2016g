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
void replaceBlank0429(char *str) {
         char blankCount = 0;
        char *pOrigin = str;
        char *pNew = str;
        while(*pOrigin) {
            if(*pOrigin == ' ') {
                ++ blankCount;
                ++pNew;
                ++pNew;
            }
            ++pOrigin;
            ++pNew;
        }
        *pNew = '\0';
        --pNew;
        --pOrigin;
        while(pOrigin != str) {
            if (*pOrigin != ' ') {
                *pNew = *pOrigin;
                --pNew;
                --pOrigin;
            } else {
                --pOrigin;
                *pNew-- = '0';
                *pNew-- = '2';
                *pNew-- = '%';
                -- blankCount;
            }
        }
        if(pNew == pOrigin) return  ;
        else {
            while(blankCount --) {
                *pNew -- = '0';
                *pNew -- = '2';
                *pNew -- = '%';
            }
            ++pNew;
        }
        
 }
int main(int argc, const char * argv[]) {
    char str01[100] = "   hello world we are happy";
    char str02[100] = " helloworld";
    replaceBlank0429(str02);
    std::cout << str02 << std::endl;
    return 0;
}
