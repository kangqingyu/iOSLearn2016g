//
//  main.cpp
//  jz35_FirstNotRepeatingChar
//
//  Created by kqy on 25/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
void firstRepeatingChar(char *str) {
    const int content = 256;
    unsigned int hashMap[content] ;
    for (int i = 0; i < content; ++i) {
        hashMap[i] = 0;
    }
    char *pMove = str;
    while (*pMove != '\0') {
        hashMap[*pMove++]++;
    }
    pMove = str;
    while (*pMove != '\0') {
        if (hashMap[*pMove] == 1) {
            cout << *pMove <<":1" <<  endl;
        }
        ++pMove;
    }
}
int main(int argc, const char * argv[]) {
    firstRepeatingChar("hellohorld");
    return 0;
}
