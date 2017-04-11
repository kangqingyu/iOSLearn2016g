//
//  main.cpp
//  algoKMP
//
//  Created by kqy on 11/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//
//想起来了，很早就有这个问题。但是一直没有搜索。2个循环for,在第2个中达到一定条件，如何跳出来第1个。如何跑到第1个条件判断中。
#include <iostream>

int isSubStr(char *strOrigin, char *strP) {
    char *pMoveOrigin = strOrigin;
    int location = 0;
    for ( ; *pMoveOrigin; ++ pMoveOrigin) {
        char *startOrigin = pMoveOrigin;
        char *startP = strP;
        while (*startOrigin == *startP) {
            ++startP;
            ++startOrigin;
        }
        
        if (*startP == '\0') {
            location = pMoveOrigin - strOrigin;
            break ; //跳出for吧
        }
    }
    return location + 1;
}
int main(int argc, const char * argv[]) {
    char str1[100] = "abcbbacbca";
    char str2[20] = "bb";
    std::cout << isSubStr(str1, str2) << std::endl;
    return 0;
}
