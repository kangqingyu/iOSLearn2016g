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
int  permutation(char *pStr, char * pStart) {
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
int main(int argc, const char * argv[]) {
//    countNumber = 0;
    char str[100] = "abc";
    int length = 3;
    cout << permutation(str, str) << endl;
    return 0;
}
