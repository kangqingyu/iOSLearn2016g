//
//  main.cpp
//  jz14_ReOrderArray_p102 second
//
//  Created by kqy on 04/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
void reOrderArray(int *array, int length) {
    int *front = array;
    int *back = array;
    while (*back) {
        ++back;
    }// back就指向了尾。
    while (front < back) {
        while ((*front & 0x1) == 1) {
            ++front;
        }
        while ((*back & 0x1) == 0) {
            --back;
        }
        if (front  < back) {
            swap(*back, *front);
            ++front;
            --back;
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
