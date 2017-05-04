//
//  main.cpp
//  jz28_stringPermutation_p155_second
//
//  Created by kqy on 09/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
 int countNumber  = 0;

void permutation(char *str, char *startStr) {
    if (*startStr == '\0') {
        cout << str << " ";
    }
    char temp;
    for (char *index = startStr; *index != '\0'; ++index) {
        temp = *index;
        *index = *startStr;
        *startStr = temp;
        permutation(str, startStr + 1);
        temp = *index;
        *index = *startStr;
        *startStr = temp;
    }
    cout << "-";
}

int main(int argc, const char * argv[]) {
//    countNumber = 0;
    char str[100] = "abc";
//    cout << permutation(str, str) << endl;
    permutation(str, str);
    return 0;
}

void permutation002(char *originStr, char *startStr){
    if (*startStr == '\0') {
        cout << originStr << " ' ";
        return;
    }
    for (char *index = startStr; *index != '\0'; ++index) {
        char temp = *index;
        *index = *startStr ;
        *startStr = temp;
        permutation(originStr, startStr + 1);
        temp = *index;
        *index = *startStr ;
        *startStr = temp;
    }
}

void permutation02(char *str, char *startStr) {
    if (*startStr == '\0') {
        cout << str << " ";
        return;
    }
    for (char  *index = startStr  ; *index  != '\0'; ++index) {
        char temp = *index;
        *index = *startStr;
        *startStr = temp;
        permutation(str, startStr + 1);
        temp = *index;
        *index = *startStr;
        *startStr = temp;
    }
}
int  permutation01(char *pStr, char * pStart) {
    if (!*pStart) {
        ++countNumber;
        cout << pStr << endl;
    } else {
        for (char * pMove = pStart; *pMove != '\0'; ++pMove) {
            char temp = *pMove;
            *pMove = *pStart;
            *pStart = temp;
            permutation( pStr, pStart + 1);
            temp = *pMove;
            *pMove = *pStart;
            *pStart = temp;
        }
    }
    return countNumber ;
}
