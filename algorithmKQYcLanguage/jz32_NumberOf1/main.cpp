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
int main(int argc, const char * argv[]) {
    cout << from1ToN(12) << std::endl;
    
    return 0;
}
