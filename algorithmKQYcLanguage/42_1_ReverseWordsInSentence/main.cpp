//
//  main.cpp
//  42_1_ReverseWordsInSentence
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
void reverseInSentence(char *str) {
    char *pEnd = str;
    while (*pEnd) ++pEnd;
    reverseWord(str, --pEnd );
    char *pStart = str;
    pEnd = str;
    while (*pStart) {
        if (*pStart == ' ') {
            ++pEnd, ++pStart;
//        } else if (*pEnd == '\0' || *pEnd == ' ') {
        } else if (*pEnd == ' ' || *pEnd == '\0' ) {
            --pEnd;
            reverseWord(pStart, pEnd);
            pStart = ++pEnd;
        } else {
            ++pEnd;
        }
//        while (*pEnd != ' ') ++pEnd;
//        --pEnd; // --pend,  pend-1一样吗？
//        reverseWord(pStart, pEnd );
//        ++pEnd;
//        while (*pEnd == ' ') ++pEnd;
//        pStart = pEnd; // first我写的，这种写法太差。
    }
}
int main(int argc, const char * argv[]) {
    char str[100] = "abc    cd ef gh    wo";
    cout << str << endl;
    reverseInSentence(str);
    cout << str << endl;
    return 0;
}
