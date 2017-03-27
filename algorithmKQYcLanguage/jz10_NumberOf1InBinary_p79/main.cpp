//
//  main.cpp
//  jz10_NumberOf1InBinary_p79
//
//  Created by kqy on 27/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iomanip>
#include <iostream>
using namespace std;
int numberInBinary02(int number) {
//    bool g_invalidValue = false;
    int count = 0;
    int compact = 1;
    while (compact) {
        if (compact & number) {
            ++count;
        }
        compact = compact << 1;
    }
    return count;
}
int numberInBinary03(int number ) {
    int count= 0 ;
    while (number) {
        ++count;
        number = number & (number - 1);
    }
    return count;
}
int main(int argc, const char * argv[]) {
    double a = 12.3241;
    std::cout<<std::setiosflags(std::ios::fixed)<<setprecision(3)<<a<<std::endl;

    std::cout << numberInBinary03(3) << std::endl;
    return 0;
}
int numberInBinary01 (int number) {
    int compact = 1;
    int numberOfPos = 0;
    int backCount = 0;
    //    int copy
    while (number) {
        ++numberOfPos;
        numberOfPos << 1;
    }
    while (numberOfPos --) {
        if (number & compact) {
            ++backCount;
        }
        compact >> 1;
    }
    return backCount;
}
