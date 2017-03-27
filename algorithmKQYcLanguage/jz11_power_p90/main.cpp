//
//  main.cpp
//  jz11_power_p90
//
//  Created by kqy on 27/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//
//1. base = 0.
// 2. exponent < 0;
#include <iostream>
bool equalValue(int, int);
double powerWithUnsigned(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else if(exponent == 1) {
        return base;
    }
    double result = powerWithUnsigned(base , exponent >> 1);
    result *= result;
#warning %2 == 1如何计算
    if (exponent %2 == 1) {
        result *= base;
    }
    return result;
}
double power02(double base, int exponent) {
#warning g_int 用  int ??
    bool g_invalidValue = false;
    if (equalValue(base, 0.0)) {
        g_invalidValue = true;
    }
    int absExponent = abs(exponent);
    double result = powerWithUnsigned(base, absExponent);
    if (exponent > 0) {
        return result;
    } else {
        return 1/ result;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << power02(3, -4) << std::endl;
    return 0;
}
bool equalValue(int number1, int number2) {
    if (number1 - number2 > -0.0000001 && number1 - number2 < 0.0000001) {
        return true;
    } else {
        return false;
    }
}
double power01(double base, int exponent) {
    if (base == 0) {
        return 0;
    } else if(exponent == 0) {
        return 1;
    }
    double result = 1;
    int zhengFu = exponent > 0 ? 1 : 0;
    int zhengExponent = abs(exponent);
    for (int i = 0; i < zhengExponent; ++i) {
        result *= base;
    }
    if (zhengFu) {
        return result;
    } else {
        return 1.0/ result;
    }
}
