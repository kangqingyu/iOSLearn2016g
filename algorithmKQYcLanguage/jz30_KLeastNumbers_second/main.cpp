//
//  main.cpp
//  jz30_KLeastNumbers_second
//
//  Created by kqy on 28/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int param(int *array, int low, int high) {
    int pivot = array[high];
    cout << pivot << "  -";
    int small = low - 1;
    for (int index = low; index < high; ++index) {
        if (array[index] < pivot) {
            ++small;
            if (index != small) {
                array[index] = array[index] + array[small];
                array[small] = array[index] - array[small];
                array[index]  = array[index] - array[small];
//                swap(array[index], array[small]);
            }
        }
    }// for
    ++small;
//    array[small] = array[small] + array[high];
//    array[high] = array[small] - array[high];
//    array[small] = array[small] - array[high];
    swap(array[small], array[high]);
    return small;
}
void findKLeastNumber(int *array, int length, int target) {
    int low = 0;
    int high = length - 1;
    int result = param(array, 0, length-1);
    while (result != target) {
        if (result > target) {
            high -= 1;
        } else low += 1;
        result = param(array, low, high);
    }
    for (int i = 0; i < result; ++i) {
        cout << array[i] << " " ;
    }
    cout << endl;
}
int main(int argc, const char * argv[]) {
    int array[9] = {23, 89, 2, 39, 12, 15, 25, 48, 57};
    findKLeastNumber(array, 9, 3);
    for (int i = 0; i < 9; ++i) {
        cout << array[i] << " ,";
    }
    return 0;
}
