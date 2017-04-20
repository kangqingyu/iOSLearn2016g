//
//  main.cpp
//  jz29_MoreThanHalfNumber_p163
//
//  Created by kqy on 19/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int paration(int *array, int low, int high, int length) {
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
int chooseMiddleNumber(int *array, int length) {
    int start = 0;
    int end = length - 1;
    int middle = length >> 1;
    int para = paration(array, start, end, length);
    while (para != middle) {
        if (para > middle) {
            end  = para  - 1;
            para = paration(array, start, end, length);
        } else {
            start = para + 1;
            para = paration(array, start, end, length);
        }
    }// while
    int middleNumber = array[middle];
    return middleNumber;
}
int main(int argc, const char * argv[]) {
    int array[13] = {3, 8, 9, 3, 4, 3, 9, 3, 8, 3, 3, 7};
    int array2[13] = {9, 8, 9, 3, 9, 3, 9, 9, 8, 9, 3, 9};
    int array3[13] = {3, 18, 9, 18, 18, 3, 9, 3, 18, 18, 18, 18};

    cout << chooseMiddleNumber(array, 11);
    cout << chooseMiddleNumber(array2, 11);
    cout << chooseMiddleNumber(array3, 11);

    return 0;
}
