//
//  main.cpp
//  jz30_KLeastNumbers
//
//  Created by kqy on 20/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int paration(int *array, int low, int high) {
    int pivot = array[high];
    int small = low - 1;
    int index;
    for (index = low; index < high ; ++index) {
        if (array[index] < pivot) {
            ++ small;
            if (index != small) {
                array[small] = array[small] + array[index];
                array[index] = array[small] - array[index];
                array[small] = array[small] - array[index];
            }
        }
    }
    ++small;
    swap(array[small], array[index]);
    return small;
}
void findKLeastNumber(int *array, int length, int k) {
    int low = 0;
    int high = length;
    int findIndex = k;
    int piv = 0;
    while ( low < high) {
        piv = paration(array, low , high);
        if (piv == findIndex) {
            break;
        }else  if (piv > findIndex) {
            high -= 1;
        } else low += 1;
    }
//    return array;
}
int main(int argc, const char * argv[]) {
    int array[9] = {13, 9, 2, 89, 12, 5, 25, 38, 97};
    findKLeastNumber(array, 9, 3);
    for (int i = 0; i < 9; ++i) {
        cout << array[i] << " ,";
    }
    std::cout << "Hello, World!\n";
    return 0;
}
