//
//  main.cpp
//  jz11_power_p90Second
//
//  Created by kqy on 03/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
long long calculate(int base, int exponent) {
    if (base == 0 ) {
        std::cout << "wrong input " << endl;
        return 0;
    } else if (exponent == 0) {
        return 1;
    }
    long long float result = 0;
    if (exponent < 0) {
        result = 1.0 / exponentWithUnsigned(base, -exponent);
    } else {
        result = exponentWithUnsigned(base, exponent);
    }
}
long long exponentWithUnsigned(int base, unsigned exponent) {
    float result = 1;
    if (exponent == 0) {
        return 1;
    }
    if (exponent %2 == 0) {
        result = 1;
    } else result = base;
    return exponentWithUnsigned(base, exponent * 0.5) * result;
}
int main(int argc, const char * argv[]) {
    
    return 0;
}
