//
//  main.cpp
//  jz32_NumberOf1_second
//
//  Created by kqy on 05/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    cout << numberOf1_method1(34) << std::endl;// method 1
    cout << numberOf1_method2(34) << endl;
    cout << numberOf1_method1(133) << std::endl;// method 1
    cout << numberOf1_method2(133) << endl;
    cout << numberOf1_method1(134) << std::endl;// method 1
    cout << numberOf1_method2(134) << endl;
    cout << numberOf1_method1(834) << std::endl;// method 1
    cout << numberOf1_method2(834) << endl;
    
    return 0;
}
int countOf1_0509(int number) {
    int count = 0;
    while (number) {
        if (number % 10 == 1) {
            ++ count;
        }
        number /= 10;
    }
    return count;
}
int numberOf1_method1_0509(int number) {
    int sum  = 0;
    for (int i = 1; i <= number; ++i) {
        sum += countOf1_0509(i);
    }
    return sum;
}
int powerWithInt_0509(int length) {
    int sum = 1;
    for (int i = 1; i < length; ++i) {
        sum *= 10;
    }
    return sum;
}
int numberOfRule_0509(char *str) {
    int firstDigit = *str - '0';
    int length = strlen(str);
    if (length < 1) {
        return 0;
    } else if (length == 1) {
        if (firstDigit < 1) {
            return 0;
        } else return 1;
    }
    int firstNumber = 0;
    if (firstDigit > 1) {
        firstNumber = powerWithInt_0509(length);
    } else firstNumber = atoi(str + 1) + 1;
    int otherNumber = firstDigit * (length - 1) * powerWithInt_0509(length - 1);
    int subNumber = numberOfRule_0509(str + 1);
    return firstNumber + otherNumber + subNumber    ;
}
int numberOf1_method2_0509(int number) {
    char strNum[89] ;
    sprintf(strNum, "%d", number);
    return numberOfRule_0509(strNum);
}

int countOf1_0505(int number) {
    int count = 0;
    while (number) {
        if (number % 10 == 1) count += 1;
        number /= 10;
    }
    return count;
}
int numberOf1_method1_0505(int number) {
    int sum = 0;
    for (int i = 1; i <= number; ++i) {
        sum += countOf1_0505(i);
    }
    return sum;
}

int power_0505(int length) {
    int sum = 1;
    for (int i = 0; i < length; ++i) {
        sum *= 10;
    }
    return sum;
}
int countOf1InStr_0505(char *str) {
    if (*str == '\0') { 
        return 0;
    }
    int length = strlen(str);
    int first = str[0] - '0';
    if (first == 0 && length == 1) {
        return 0;
    }
    if (length == 1 && first > 0) {
        return 1;
    }
    int totalCount = 0;
    int firstDigitCount = 0;
    int otherDigitCount = 0;
      //first 和*first有区别吗？
//    if (str[0] > 1)  firstDigitCount = power(length-1);
        if (first > 1)  firstDigitCount = power_0505(length-1);
    else firstDigitCount = atoi(str + 1) + 1;
    otherDigitCount = (length - 1) * first * power_0505(length - 2);
    //first 和*first有区别吗？
    totalCount = firstDigitCount + otherDigitCount + countOf1InStr_0505(str + 1);
    return totalCount;
}
int numberOf1_method2_0505(int number) {
    char str[100] ;
    sprintf(str, "%d", number);
    return countOf1InStr_0505(str);
}


