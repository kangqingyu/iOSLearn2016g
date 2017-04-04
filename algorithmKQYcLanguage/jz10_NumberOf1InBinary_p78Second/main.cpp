//
//  main.cpp
//  jz10_NumberOf1InBinary_p78Second
//
//  Created by kqy on 03/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
int countInBinary(int number) {
    int count = 0;
    while (number) {
//        if (number & (number -1)) {
            ++count;
//        }
        number = number & (number -1);
    }
    return count;
}
int main(int argc, const char * argv[]) {
    std::cout << countInBinary(6) << std::endl;
    return 0;
}
