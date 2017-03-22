//
//  main.c
//  jz04_ReplaceBlank_p45
//
//  Created by kqy on 22/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <stdio.h>
#define maxNumber 99
void changeStrBlack(char *strHead) {
    char *pHead = strHead;
    while (pHead) {
        if (*pHead == ' ') {
            //向后移动
            char *pEnd = pHead;
            while (pEnd) {
                --pEnd;
            }//while结束后p 指向了空 '\0';
            *(pEnd +2) = '\0';
            *(pEnd +1) = *(pEnd -1);
            while (pEnd != pHead) {
                *pEnd = *(pEnd - 2);
                -- pEnd;
            }
            *pEnd = '%';
            *(pEnd + 1) = '2';
            *(pEnd + 2) = '0';
        } else {
            ++pHead;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    char  str1[maxNumber] = "hello world what about   ok";
    changeStrBlack(str1);
    puts(str1);
    return 0;
}
