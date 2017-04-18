//
//  main.cpp
//  jz12_print1ToMaxOfDigits_p95_second
//
//  Created by kqy on 18/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
bool increase(char *n) {
    int length = strlen(n);
    int isOverFlow = 0;
    int result = false;
    for (int i = length - 1; i >= 0 ; --i ) {
        int summer = n[i] - '0' + isOverFlow;
        if (i == length - 1) ++ summer;
        if (summer >= 10) {
            if (i == 0) {
                result = true;
                return result;
            } else {
                summer -= 10;
                isOverFlow = 1;
                n[i] = '0' + summer;
            }
            
        } else {
            n[i] = summer + '0';
            break;
        }
    }
    return result;
}
void printToN(char *n) {
    int nLength = strlen(n);
    int zeroStart = 1;
    for (int i = 0; i < nLength; ++i) {
        if (zeroStart && n[i] == '0') {
            continue;
        } else {
            zeroStart = 0;
        }
        if (!zeroStart) {
            cout << n[i]  ;
        }
    }
}
void print1ToN(int n) {
    char *numbers = new char[n+1];
    memset(numbers, '0', n);
    numbers[n+1] = '\0';
    while (!increase(numbers)) {
        printToN(numbers);
        cout << " ";

    }
}
int main(int argc, const char * argv[]) {
    print1ToN(2);
    
    return 0;
}
