//  
//  main.cpp
//  sort_qzbd_p250
//
//  Created by kqy on 27/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
//#include <algorithm>
//#include <string>
//#include <string.h>
#include<cstring>

#define arrayLength 10
using namespace std;
void insertSort01 (int array[], int length) {
    int j;
    for (int i = 2; i < length; ++i) {
        array[0] = array[i];//哨兵
        for (  j = i -1 ; array[j] > array[0]; --j ) {
            array[j+1] = array[j];
        }// for j
        array[++j] = array[0];
    }// for i
//    array[0] = 999;
}
void shellInsertSort(int *array, int length) {
    for (int step = length / 2; step >=1; step  /= 2) {
        for (int i = step + 1; i < length ; ++i) {
            array[0] = array[i];
            int j;
            for ( j = i-step ; j >0; j -= step ) {
                if (array[j] > array[0]) {
                    array[j + step] = array[j];
                }
            }// for j
            array[j+step] = array[0];
        }// for i
    }// for step
    array[0] = 999;
}
void buddleSort01(int *array, int length) {
    int temp ;
    for (int i = length - 1; i > 0; --i ) {
        for (int j = i - 1; j >= 0 ; --j) {
            if (array[j] > array[i]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int param01(int *array, int low, int high ) {
//    int min = array[0];
    int pivot = array[low];
    while (low < high) {
        while (array[high] > pivot  && low < high)  -- high;
//            array[high] = array[low];
        array[low] = array[high];
        while (array[low]< pivot  && low < high ) ++low;
        array[high] = array[low];
        
    }// while
    array[low] = pivot;
    return low;
}
int partition02(int *array, int low, int high) {
    int end = high;
    int small = low - 1;
    int index = low;
    for (  ; index  < high; ++ index ) {
        if (array[index] < array[end]) {
            ++small;
            if (index != small) {
                std::swap(  array[small],  array[index]);
                
            }
        }
    }// for
    ++small;
    swap(array[small], array[end]);
    
    return small;
}
void quickSort(int *array, int low, int high) {
    if (low < high) {
    int parament =  partition02(array,  low, high );
    quickSort(array , low, parament -1);
    quickSort(array, parament + 1, high);
    }
}
int main(int argc, const char * argv[]) {
    int array0[arrayLength] = {999, 7, 5, 9, 23, 98, 4, 19, 6};
//    insertSort01(array0, 9);
//    shellInsertSort(array0, 9);
//    buddleSort01(array0, 9);
    quickSort(array0, 0, sizeof(array0)/ sizeof(array0[0]));
//    cout << strlen(array0) ;

    std::cout << std::endl;
    for (int i = 0; i < arrayLength; ++i) {
        std::cout << array0[i] <<  "  ";
    }
    std::cout << std::endl;
    return 0;
}
