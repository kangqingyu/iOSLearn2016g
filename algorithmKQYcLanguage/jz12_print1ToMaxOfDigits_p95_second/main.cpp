//
//  main.cpp
//  jz12_print1ToMaxOfDigits_p95_second
//
//  Created by kqy on 18/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
bool increase(char *number) {
    int overFlow = 0;
    int takeOver = 0;
    int sum = 0;
    int length = strlen(number);
    for (int i = length -1; i >= 0; --i) {
        sum = number[i] - '0' + takeOver;
        if (i == length - 1) {
            ++sum;
        }
        if (sum >= 10) {
            if (i == 0) {
                overFlow = 1;
//                break;//多余
            } else {
                takeOver = 1;
                sum -= 10;
                number[i] = sum + '0';
            }
        } else {
            number[i] = '0' + sum;
            break;
        }
    }
    return overFlow;
}
void printNumber(char *number) {
    int zeroStart = 1;
    int   length = strlen(number);
    for (int i = 0; i < length  ; ++i ) {
        if (zeroStart && number[i] != 0) {
            zeroStart = 0;
        }
        if (!zeroStart) {
            cout << number[i];
        }
    }
    cout << "   ";
}
void print1ToN(int digit) {
    char *number = new char[digit + 1];
    memset(number, '0', digit);
    number[digit + 1] = '\0' ;
    while (!increase(number)) {
        printNumber(number);
    }
}
void print1ToNRecurivively_0425(char *numbers, int length, int index) {
    if (index == length-1) {
        printNumber(numbers);
        return;
    }
    for (int i = 0; i < 10; ++i) {
        numbers[index + 1] = '0' + i;
        print1ToNRecurivively_0425(numbers, length, index + 1);
    }
}
void print1ToN_method2_0425(int digit) {
    char *numbers = new char[digit+1];
    memset(numbers, '0', digit);
    numbers[digit+1] = '\0' ;
    for (int i = 0; i < 10; ++i) {
        numbers[0] = '0' + i;
        print1ToNRecurivively_0425( numbers, digit, 0);
    }
}
int main(int argc, const char * argv[]) {
//    print1ToN(3);
    print1ToN_method2_0425(3);
    return 0;
}

//0420
bool increase0420(char *numbers) {
    int overFlow = 0;
    int takeOver = 0;
    int length = strlen(numbers);
    int sum = 0;
    for (int i = length -1; i >= 0; --i) {
        sum = numbers[i] - '0' + takeOver;
        if (i == length - 1) {
            sum += 1;
        }
        if (sum >=10) {
            if (i == 0) {
                overFlow = 1;
            } else {
                sum -= 10;
                takeOver = 1;
                numbers[i] = sum + '0';
            }
        } else {
            numbers[i] = '0' + sum;
            break;
        }
    }
    return overFlow;
}
void printThese0420(char *numbers) {
    int length = strlen(numbers);
    int zeroDigit = 1;
    for (int i = 0; i < length; ++i) {
        if (zeroDigit && numbers[i] != '0') {
            zeroDigit = 0;
        }
        if (!zeroDigit) {
            cout << numbers[i] ;
        }
    }
    cout << " ";
}
void print1ToN0420(int digit) {
    char *numbers = new char[digit + 1];
    memset(numbers, '0', digit);
    numbers[digit] = '\0';
    while (!increase0420(numbers)) {
        printThese0420(numbers);
    }
}
//0418
bool increase01(char *n) {
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
void printToN01(char *n) {
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
void print1ToN01(int n) {
    char *numbers = new char[n+1];
    memset(numbers, '0', n);
    numbers[n+1] = '\0';
    while (!increase01(numbers)) {
        printToN01(numbers);
        cout << " ";

    }
}

