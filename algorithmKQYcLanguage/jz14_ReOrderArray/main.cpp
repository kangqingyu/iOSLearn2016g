//
//  main.cpp
//  jz14_ReOrderArray
//
//  Created by kqy on 28/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
#include <string>
void swap(int *p, int *q) {
    int temp = 0;
    temp = *p;
    *p = *q;
    *q = temp;
}
void reOrderArray(int *array, int length) {
    int *pHead = array;
    int *pRear = &array[length - 2];
    while (pHead < pRear) {
        if ((*pHead &0x1) == 1) {
            ++pHead;
        }
        if ((*pRear &0x1) == 0) {
            --pRear;
        }
        if (((*pHead & 0x1) ==0) && ((*pRear & 0x1) == 1)) {
            swap(pHead, pRear);
            ++pHead;
            --pRear;
        }
    }
}
int main(int argc, const char * argv[]) {
    int array1[10] = {3, 4, 2, 5, 23, 42, 15, 8, 9};
    int array2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrLength = 10;
    reOrderArray(array2, arrLength);
    for (int i = 0; i < arrLength; ++i) {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
