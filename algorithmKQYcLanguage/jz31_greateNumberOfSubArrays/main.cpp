//
//  main.cpp
//  jz31_greateNumberOfSubArrays
//
//  Created by kqy on 20/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
int GreateNumber(int *array, int length) {
    int greateNumber = 0;
    int tempNumber = 0;
    for (int i = 0; i < length; ++i) {
//        tempNumber = (tempNumber + array[i]) > 0 ? (tempNumber + array[i] ) : array[i];
        if (tempNumber <= 0) {
            tempNumber = array[i];
        } else tempNumber += array[i];
//        greateNumber = tempNumber > greateNumber ? tempNumber : greateNumber;
        if (tempNumber > greateNumber) {
            greateNumber = tempNumber;
        }
    }
    return greateNumber;
}
int main(int argc, const char * argv[]) {
    int array1[9] = {1, -2, 3, 10, -4, 7, 2, -5, 4};
    int array[9] = {1,2,3,4,5,6,7,8,-9};
    std::cout << GreateNumber(array, 9);
    return 0;
}
