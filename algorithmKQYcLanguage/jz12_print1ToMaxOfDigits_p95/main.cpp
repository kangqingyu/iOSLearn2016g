//
//  main.cpp
//  jz12_print1ToMaxOfDigits_p95
//
//  Created by kqy on 09/04/2017.
//  Copyright © 2017 jogging. All rights reserved.
//

#include <iostream>
#include <string>
#include <memory>

using namespace std;
bool increateToMax(char *numbers) ;
void printNumber(char * numbers ) ;
void print1toMaxN(int digit) {
    char *numbers = new char[digit + 1];
    memset(numbers, '0', digit);
    numbers[digit + 1] = '\0';
    while (!increateToMax(numbers)) {
        printNumber(numbers);
    }
}
bool increateToMax(char *numbers) {
    int stackOverFlow = 0;
    int takeOver = 0;
    int length = strlen(numbers);
    for (int i = length - 1; i >= 0; --i) {
        int sum = numbers[i] - '0' + takeOver;
        if (i == length  -1) {
            ++sum;
        }
        if (sum >= 10) {
            if (i == 0) {
                stackOverFlow = 1;
            } else {
                sum -= 10;
                takeOver = 1;
                numbers[i] = sum + '0';
            }
        } else {
            numbers[i] = sum + '0';
            break;
        }// else sum <10
    }
    return stackOverFlow;
}
void printNumber(char * numbers ) {
    int length = strlen(numbers);
    int startZero = 0;
    for (int i = 0; i < length ; ++ i) {
        if (!startZero && numbers[i] != '0') {
            startZero = 1;
        }
        if (startZero) {
            cout << numbers[i]  ;
        }
    }
    cout << "  ";
}
int main(int argc, const char * argv[]) {
    print1toMaxN(2);
    return 0;
}
