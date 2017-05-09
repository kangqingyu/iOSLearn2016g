//
//  main.cpp
//  44_continousCards
//
//  Created by kqy on 08/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int compare(const void *arg1, const void *arg2) {
    return *(int *)arg1 - *(int *)arg2;
}
bool isContinous(int *numbers, int length) {
    int zeroNumber = 0;
    int distance = 0;
    int front , back;
    qsort(numbers, length, sizeof(int), compare);
    for (int i = 0; i < length; ++ i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < length && numbers[i] == 0; ++i) ++zeroNumber;
    front = numbers[zeroNumber];
    back = numbers[zeroNumber];
    for (int i = zeroNumber + 1; i < length; ++i) {
        front = numbers[i];
        if (front == back) {
            return false;
        }
        distance += (front - back - 1);
        back = front;
    }
    if (zeroNumber >= distance) {
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int array[8] = {10, 4, 5, 7, 0, 8, 10, 9};
    bool b1 = isContinous(array, sizeof(array) / sizeof(int));
    cout << b1 << endl;
    return 0;
}
