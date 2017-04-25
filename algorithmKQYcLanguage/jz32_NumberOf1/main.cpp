//
//  main.cpp
//  jz32_NumberOf1
//
//  Created by kqy on 20/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int numberOf1(int);
int from1ToN(int number) {
    int sum = 0;
    for (int i = 0; i <= number ; ++i) {
        sum += numberOf1(i);
    }
    return sum;
}
int numberOf1(int number) {
    int sum = 0;
    while (number) {
        if (number %10 == 1) {
            ++sum;
        }
        number /= 10;

    }
    return  sum;
 }
int power10(int length) {
    int result = 1;
    for (int i = 0; i < length; ++i) {
        result *= 10;
    }
    return result;
}
int numberOf1_met2(char *numbers) {
    if (*numbers == '\0') {
        return 0;
    }
    int firstDigit = numbers[0] - '0';
    int firstCount = 0;
    int totalCount = 0;
    int length = strlen(numbers);
//    int length = static_cast<unsigned int >(strlen(numbers));
    if (firstDigit > 1) {
        firstCount = power10(length - 1 );
    } else if (firstDigit == 1) {
        firstCount = atoi(numbers + 1) + 1;
    }
    int otherNumber = firstDigit * power10(length - 2) * (length - 1) ;
    int circleDigitNumber = numberOf1_met2(numbers + 1);
    return firstCount + otherNumber + circleDigitNumber;
    
}
int numberOf1_method2(int number) {
    if (number < 0) {
        return 0;
    }
    char str[89];
    sprintf(str, "%d", number);
    return numberOf1_met2(str);
}
int main(int argc, const char * argv[]) {
    cout << numberOf1_method2(5134) << endl;
    cout << from1ToN(5134) << std::endl;// method 1
    
    return 0;
}
