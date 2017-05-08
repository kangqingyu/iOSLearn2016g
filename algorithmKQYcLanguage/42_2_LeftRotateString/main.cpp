//
//  main.cpp
//  42_2_LeftRotateString
//
//  Created by kqy on 08/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
void reverseWord(char *start, char *end) {
    if (start >= end) {
        return;
    }
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        ++start, --end;
    }
}
void leftRotatedStr(char *str, int startLocation) {
    char *pStart = str;
    char *pEnd = str;
    while (*pEnd) ++pEnd;
    --pEnd;
    char *pMiddle = pStart;
    for (int i = 1; i < startLocation; ++i)  ++ pMiddle;
    reverseWord(pStart, pMiddle);
    reverseWord(++pMiddle, pEnd);
    reverseWord(pStart,  pEnd);

}
int main(int argc, const char * argv[]) {
    char str[100] = "abcdefgh";
    cout << str << endl;
    leftRotatedStr(str, 2);
    cout << str << endl;
    return 0;
}
