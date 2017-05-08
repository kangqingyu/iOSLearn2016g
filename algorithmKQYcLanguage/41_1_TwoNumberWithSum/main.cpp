//
//  main.cpp
//  41_1_TwoNumberWithSum
//
//  Created by kqy on 08/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
void twoSummer(int *array, int target, int length) {
    int targetArray[2]= {999, 99};
    int *front = array;
    int *back = array + length - 1;
    while (front < back) {
        if (*front + *back == target) {
            targetArray[0] = *front;
            targetArray[1] = *back;
            break;
        } else if (*front + *back > target) --back;
        else ++front;
    }
//    return targetArray;
    cout << targetArray[0] << " " << targetArray[1] << endl;
}
int main(int argc, const char * argv[]) {
    int array[6] = {1, 2, 4, 7, 11, 15};
    int target = 6;
//    int array2[2] ={0};
//    array2 = twoSummer(array, target, 6); // 数组不可以赋值。
    twoSummer(array, target, 6);
    return 0;
}
