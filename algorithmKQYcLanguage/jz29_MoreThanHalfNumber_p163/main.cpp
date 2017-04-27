//
//  main.cpp
//  jz29_MoreThanHalfNumber_p163
//
//  Created by kqy on 19/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int param(int *array, int low, int high) {
    int small = low - 1;
    int pivot = array[high];
    for (int index = low; index < high; ++index) {
        if (array[index] < pivot) {
            ++small;
            if (index != small) {//好像一直都不相等啊
                array[small] = array[small] + array[index];
                array[index] = array[small] - array[index];
                array[small] = array[small] - array[index];
            }
        }
    }
    ++small;
    swap(array[small], array[high]);
    return small;
}
int chooseMiddleNumber(int *array, int length) {
    int middle = length >> 1;
    int low = 0;
    int high = length - 1;
    int index = param(array, low, high);
    while (middle != index) {
        if (index < middle) {
            low += 1;
            index = param(array, low, high);
        } else {
            high -= 1;
            index = param(array, low, high);
        }
    }
    return array[middle];
}
int main(int argc, const char * argv[]) {
    int array[13] = {3, 8, 9, 3, 4, 3, 9, 3, 8, 3, 3, 7};// 3, 9, 18;
    int array2[13] = {9, 8, 9, 3, 9, 3, 9, 9, 8, 9, 3, 9};
    int array3[13] = {3, 18, 9, 18, 18, 3, 9, 3, 18, 18, 18, 18};
    int array4[7] = {8,23, 14, 8, 2, 8, 8};
    cout << chooseMiddleNumber(array, 11) << "  ";
    cout << chooseMiddleNumber(array2, 11) << "  ";
    cout << chooseMiddleNumber(array3, 11) << "  ";
    cout << chooseMiddleNumber(array4, 8) << "  ";
    return 0;
}
int paration0419(int *array, int low, int high, int length) {
    int small= low -1;
    int pivot = array[high];
    for (int index = low ; index < high; ++index) {
        if (array[index] < pivot) {
            ++small;
            if (index != small) {
                swap(array[index], array[small]);
            }
        }
    }
    ++small;
    swap(array[small], array[high]);
    return small;
}
int chooseMiddleNumber0419(int *array, int length) {
    int start = 0;
    int end = length - 1;
    int middle = length >> 1;
    int para = paration0419(array, start, end, length);
    while (para != middle) {
        if (para > middle) {
            end  = para  - 1;
            para = paration0419(array, start, end, length);
        } else {
            start = para + 1;
            para = paration0419(array, start, end, length);
        }
    }// while
    int middleNumber = array[middle];
    return middleNumber;
}

  
