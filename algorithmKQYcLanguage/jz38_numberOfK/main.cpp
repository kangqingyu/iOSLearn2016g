//
//  main.cpp
//  jz38_numberOfK
//
//  Created by kqy on 27/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int firstK(int * array, int length, int k, int start, int end) {
    int middle = (start + end) >> 1;
    if (array[middle] == k) {
#warning 这个条件。 0427. 14:38
        if (start >= 0 && array[middle-1] != k) { //
            return middle ;
        } else {
            end = middle - 1;
        }
    } else if(array[middle] > k) {
        end = middle - 1;
    } else start = middle + 1;
    return firstK(array, length, k, start, end);
}
int lastK(int *array, int length, int k , int start, int end) {
    int middle = (start + end) >> 1;
    if (array[middle] == k) {
        if (array[middle + 1] != k) {
            return middle;
        } else start = middle + 1;
    } else if (array[middle] > k) {
        end = middle - 1;
    } else start = middle + 1;
    return lastK(array, length, k, start, end);
}

int numberOfK(int *array, int length, int k) {
    int first = firstK(array, length, k, 0, length- 1);
    int last = lastK(array, length, k, 0, length - 1);
    return last - first + 1;
}
int main(int argc, const char * argv[]) {
    int array[10] = {1, 2, 3, 4, 5, 5, 5, 5, 5, 6};
    cout << firstK(array, 10,1, 0, 9) <<" " <<lastK(array, 10, 1, 0, 9) << endl;
    cout << numberOfK(array, 10, 1);
    return 0;
}
