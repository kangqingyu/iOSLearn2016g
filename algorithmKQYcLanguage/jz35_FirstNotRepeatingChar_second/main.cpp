//
//  main.cpp
//  jz35_FirstNotRepeatingChar_second
//
//  Created by kqy on 06/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
char firstNotRepeatingChar(char *str) {
    char hashMap[256] = {0};
    char *pMove = str;
    while (*pMove != '\0') {
        hashMap[*pMove++] ++;
    }
    pMove = str;
    while (*pMove != '\0') {
        if (hashMap[*pMove] == 1) {
            return *pMove;
        }
        pMove ++;
    }
    return -1;//not good. use : '\0' .
}
int main(int argc, const char * argv[]) {
    char str[100] = "dhelloworldeh";
    cout << firstNotRepeatingChar(str);
    return 0;
}
