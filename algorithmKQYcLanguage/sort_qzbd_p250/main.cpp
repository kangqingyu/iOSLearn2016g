//  
//  main.cpp
//  sort_qzbd_p250
//
//  Created by kqy on 27/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
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
    array[0] = 999;
}
int main(int argc, const char * argv[]) {
    int array0[arrayLength] = {999, 7, 5, 9, 23, 98, 4, 19, 6};
    insertSort01(array0, 9);
    std::cout << std::endl;
    for (int i = 0; i < arrayLength; ++i) {
        std::cout << array0[i] <<  "  ";
    }
    std::cout << std::endl;
    return 0;
}
