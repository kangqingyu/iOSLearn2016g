//
//  main.cpp
//  jz09_reverseAdd_p71
//
//  Created by kqy on 24/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
int addContinousNumbers(int border) {
//    int result = 1;
//    if(border <1) return 0;
////    if(border = 1) return 1;
//    return (border +  addContinousNumbers(border - 1));
    return border < 1 ? 0 : (border + addContinousNumbers(border - 1));
}
int addContinousNumberUseFor(int border) {
    int result = 0;
    for (int i = 1; i <= border; ++i ) {
        result += i;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int result = addContinousNumbers(1);
    std::cout << result << std::endl;
    int result2 = addContinousNumberUseFor(5);
    std::cout << result2 << std::endl;
    return 0;
}
