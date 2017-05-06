//
//  main.cpp
//  jz38_numberOfK_second
//
//  Created by kqy on 06/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int getFirstLoc(int *array, int low, int high, int length, int target) {
    if (low == high) {
        return low;
    }
    if (low > high) return -1;
    int middle = (low + high) >> 1;
    if (array[middle] == target) {
        if (array[middle -1] != target || middle == 0) {
            return middle;
        }  else high = middle -1;
    } else if (array[middle] > target) {
        high = middle - 1;
    } else if (array[middle] < target) {
        low = middle + 1;
    }
    return getFirstLoc(array, low, high, length, target);
}
int getBackLoc(int *array, int low, int high, int length, int target) {
    if (low == high) {
        return low;
    }
    if (low > high) return -1;

    int middle = (low + high) >> 1;
    if (array[middle] == target ) {
        if (array[middle+1] != target || middle ==length -1) {
            return middle;
        } else low = middle + 1;
    } else if (array[middle] > target) high = middle - 1;
    else low = middle + 1;
    return getBackLoc(array, low, high, length, target);
}
int numberOfK(int *array, int length, int target) {
    int front = getFirstLoc(array, 0, length -1, length, target);
    int back = getBackLoc(array, 0, length - 1, length, target);
    return back - front + 1;
}
int main(int argc, const char * argv[]) {
    int array[10] = {1, 2, 3, 4, 5, 5, 5, 5, 5, 6};
    cout << getFirstLoc(array, 10,0, 9, 5) <<" " <<getBackLoc(array, 10, 0, 9, 5) << endl;
    cout << numberOfK(array, 10, 5);
    return 0;
}
