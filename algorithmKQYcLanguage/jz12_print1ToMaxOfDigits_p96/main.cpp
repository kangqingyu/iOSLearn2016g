//
//  main.cpp
//  jz12_print1ToMaxOfDigits_p96
//
//  Created by kqy on 09/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
void printNumber(char *numbers) {
    int startZero = 0;
    for (int i = 0; i < strlen(numbers); ++i) {
        if (!startZero && numbers[i] != '0') {
            startZero = 1;
        }
        if (startZero) {
            cout << numbers[i] ;
        }
    }// for
    cout << "   ";
}
void printCurivisily(char *numbers, int length, int index) {
    if (index == length - 1) {
        printNumber(numbers);
        return ;
    } else {
        for (int i = 0; i < 10; ++ i) {
            numbers[index+1] = '0' + i;
            printCurivisily(numbers, length, index + 1);
        }
    }
}
void print1ToMaxN(int digit) {
    if (digit < 0) return ;
    char *numbers = new char[digit + 1];
    memset(numbers, '0', digit);
    numbers[digit] = '\0';
    int index = 0;
    for (int i = 0; i < 10; ++i ) {
        numbers[index] = '0' + i;
        printCurivisily(numbers, digit, index);
    }
}
int main(int argc, const char * argv[]) {
    print1ToMaxN(3);
    return 0;
}
