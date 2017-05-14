//
//  main.cpp
//  jz38_numberOfK_second
//
//  Created by kqy on 06/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int array[10] = {1, 2, 3, 4, 4, 5, 5, 5, 5, 6};
    cout << getFirstLoc(array,  0, 9, 4) <<" " ;
    cout <<getBackLoc(array, 0, 9, 4 ) << endl;
    cout << numberOfK(array, 10, 4);
    return 0;
}
int getFirstLoc0513(int *array, int low, int high, int target) {
    if (low > high) return -1;
    int middle = (low + high) >> 1;
    //以前多写了外层的if (low < high)这是错误的。
        if (target == array[middle]) {
            if ((middle  == 0) || (middle > 0 && array[middle-1] != target)) {
                return middle;
            } else high = middle - 1;
        } else if (array[middle] > target) high = middle - 1;
        else low = middle + 1;
    
    return getFirstLoc0513(array, low, high, target);
}
int getBackLoc0513(int *array, int low, int high, int target) {
    if (low > high) return -1;
    int middle = (low + high) >> 1;
  
        if (array[middle] == target) {
            if (middle == high || (middle < high && array[middle+1] != target )) {
                return middle;
            } else low = middle + 1;
        } else if (array[middle] > target) high = middle - 1;
        else low = middle + 1;
   
    return getBackLoc0513(array, low, high, target);
}
int numberOfK0513(int *array, int length, int target) {
    int low = getFirstLoc0513(array, 0, length - 1, target);
    int high = getBackLoc0513(array, 0, length - 1, target);
    return high - low + 1;
}


int getFirstLoc0508(int *array, int target, int low, int high) {
    if (low > high) {
        return -1;
    }
    int middle = (low + high) >> 1;
    while (low < high) {
        if (array[middle] == target) {
            if (array[middle -1] != target || (middle == low)) {
                return middle;
            } else high = middle - 1;
        } else if (array[middle] > target) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
        middle = getFirstLoc0508(array, target, low, high);
    }
    return middle;
}
int getBackLoc0508(int *array, int target, int low, int high) {
    if (low > high) return -1;
    int middle = (low + high) >> 1;
    while (low < high) {
        if (array[middle] == target ) {
            if ( array[middle +1] != target || middle == high ) return middle;
            else low = middle + 1;
        } else if (array[middle] > target) high = middle - 1;
        else low = middle + 1;
        middle = getBackLoc0508(array, target, low, high);
    }
    return middle;
}
int numberOfK0508(int *array, int length, int target) {
    int low = getFirstLoc0508(array, target, 0, length - 1);
    int high = getBackLoc0508(array, target, 0, length - 1);
    return high - low  + 1;
}

int getFirstLoc0504wrong(int *array, int low, int high, int length, int target) {
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
    return getFirstLoc0504wrong(array, low, high, length, target);
}
int getBackLoc0504wrong(int *array, int low, int high, int length, int target) {
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
    return getBackLoc0504wrong(array, low, high, length, target);
}
int numberOfK0504wrong(int *array, int length, int target) {
    int front = getFirstLoc0504wrong(array, 0, length -1, length, target);
    int back = getBackLoc0504wrong(array, 0, length - 1, length, target);
    return back - front + 1;
}
