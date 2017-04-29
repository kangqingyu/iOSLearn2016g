//
//  main.cpp 
//  jz31_greateNumberOfSubArrays_second
//
//  Created by kqy on 28/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int GreatNumber(int *array, int length) {
    int tempSum = array[0];
    int temp ;
    int max = 0;
    for (int i = 1; i <length; ++i ) {
        tempSum += array[i];
        if (tempSum >= max) {
            max = tempSum;
        } else {}
        if (tempSum < 0) {
            ++i;
            tempSum = array[i];
        }
    }
    return max;
}
int main(int argc, const char * argv[]) {
    int array1[9] = {1, -2, 3, 10, -4, 7, 2, -5, 4};// 18
    int array[9] = {1,2,3,4,5,6,7,8,-9};
    std::cout << GreatNumber(array1, 9);
    return 0;
}
