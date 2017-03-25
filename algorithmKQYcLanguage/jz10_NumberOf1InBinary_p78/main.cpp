//
//  main.cpp
//  jz10_NumberOf1InBinary_p78
//
//  Created by kqy on 24/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
int numberInBinary(int target) {
    int count = 0;
    while (target) {
        if (target & 1) {
            ++count;
        }
        target = target >> 1;
    }
    return count;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::cout << numberInBinary(8) << std::endl;
    return 0;
}
