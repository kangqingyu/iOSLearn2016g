//
//  main.c
//  jz04_ReplaceBlank_p46
//
//  Created by kqy on 22/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <stdio.h>
#define maxNumber 100
void changeBlackStr(char *pStr, int length) {
    char *pHead = pStr;
    char *pNew;//指向新的字符串的最后一个结点。
    int blankCount = 0;
    int strLength = 0;
    while (*pHead /*!='\0'*/) {
        ++strLength;
        if (*pHead == ' ') {
            ++blankCount;
        }// if
        ++pHead;
    }// while
    printf("black:%d, length:%d\n", blankCount, strLength);
    //判断总长是否足够
    if (length <= blankCount + strLength) {
        printf("not enouch length");
        return ;
    }
    int newLoc = blankCount * 2 + strLength;
    pHead --;// pHead  移动到了最开始的位置。
    pStr[newLoc--] = '\0';
    while (newLoc && strLength) {
        if (*pHead ==' ') {
            pStr[newLoc--] = '0';
            pStr[newLoc--] = '2';
            pStr[newLoc--] = '@';
            --pHead;
        } else {
            pStr[newLoc--] = *pHead;
            --pHead;
        }
        -- strLength;//等同于 --pHead的作用。只不过*pHead我没有用下标。
    }
    
}
int main(int argc, const char * argv[]) {
     char  str1[maxNumber] = " about ok hello world 111111what   ";
    puts(str1);

    changeBlackStr(str1, 60);
    puts(str1);
    return 0;
}
