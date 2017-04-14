//
//  main.cpp
//  sort02_qzbd_p250
//
//  Created by kqy on 10/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
#define arrayLength 12
using namespace std;
int partition01(int *array, int low, int high) {
    int compact  = array[low];
//    int *back = array;
//    int *front = array + high - 1;
    while (low  < high) {
        while (array[high] > compact && low  <high )            -- high;
        array[low] = array[high];
        while ( array[low] < compact && low < high)            ++ low;
        array[high] = array[low];
    }
    array[low] = compact;
    return low;
}
int partition02(int *array, int low, int high) {
    int small = low -1;
    int pivotPos = array[high];
    for (int i = low; i < high; ++ i) {
        if (array[i] < pivotPos) {
           ++small;
            if (i != small) {
                swap(array[i], array[small]);
            }
        }
    }
    ++small;
    swap(array[small], array[high]);
    return small;
}
int partition02_second(int *array, int low, int high) {
    int small = low -1;
    int pivot = array[high];
    for (int index = low ; index < high; ++index) {
        if (array[index] < pivot) {
            ++small;
//            if (index != small) {
            swap(array[index], array[small]);
//            }
        }
    }
//    ++small;
    swap(array[++small], array[high]);
    return small;
}

int partition01_second(int * array, int low, int high) {
    int pivot = array[low];
    while (low < high) {
        while (array[high] > pivot && low < high) --high;
        array[low] = array[high];
        while (array[low] < pivot && low < high) ++low;
        array[high] = array[low];
    }
    array[low] = pivot;
    return low;
}
void quickSort01_second(int *array, int low, int high) {
    if (low < high ) {
        int middle = partition02_second(array, low, high );
        quickSort01_second(array, low, middle -1);
        quickSort01_second(array, middle +1, high);
    }
}
void selectSort(int *array, int length) {
    int minLoc = 0;
    for (int i = 0; i < length; ++i) {
        int minNum = array[i];
        minLoc = i;
        for (int j = i + 1; j < length; ++j) {
            if (minNum > array[j]) {
                minNum = array[j];
                minLoc = j;
            }
        }
        swap(array[i], array[minLoc]);
    }
}
void adjustDown(int * array, int kElement, int length) {
    
}
void buildMaxHeap(int *array, int length) {
    for (int i = length / 2; i  > 0; -- i ) {
        adjustDown(array, i, length);
    }
}
int main(int argc, const char * argv[]) {
    int array0[arrayLength] = {12, 10, 7, 5, 89, 9, 23, 98, 4, 78, 19, 6};
//    quickSort01_second(array0, 0, sizeof(array0)/ sizeof(array0[0]));
//    selectSort(array0, sizeof(array0)/ sizeof(array0[0]));
//    buildMaxHeap(array0, sizeof(array0)/ sizeof(array0[0]));
      quickSort01_second(array0, 0, sizeof(array0)/ sizeof(array0[0]));

    std::cout << std::endl;
    for (int i = 0; i < arrayLength; ++i) {
        std::cout << array0[i] <<  "  ";
    }
    std::cout << std::endl;
    return 0;
}
