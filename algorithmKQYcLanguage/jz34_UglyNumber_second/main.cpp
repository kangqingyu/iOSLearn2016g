//
//  main.cpp
//  jz34_UglyNumber_second
//
//  Created by kqy on 29/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int minNumber(int n1, int n2, int n3) {
    int min = n1 < n2 ? n1 : n2;
    min = min < n3 ? min : n3;
    return min;
}
int theKUglyNumber(int target) {
    int *numbers = new int[target + 2];
    numbers[0] = 1;
    int *move = numbers;
    ++move;
    int min = 1;
    int * mul2 = numbers;
    int *mul3 = numbers;
    int *mul5 = numbers;
    for (int i = 0; i < target; ++ i ) {
        min = minNumber(*mul2 * 2, *mul3 * 3, *mul5 * 5) ;
        *move = min;
        ++move;
        while (*mul2 * 2 <= min) {
            ++mul2;
        }
        while (*mul3 * 3 <= min) {
            ++mul3;
        }
        while (*mul5 * 5 <= min) {
            ++mul5;
        }
    }
    return min;
}
int main(int argc, const char * argv[]) {
    cout << theKUglyNumber(1) << endl;
    cout << theKUglyNumber(2) << endl;
    cout << theKUglyNumber(3) << endl;
    cout << theKUglyNumber(4) << endl;
    cout << theKUglyNumber(5) << endl;
    cout << theKUglyNumber(6) << endl;
    cout << theKUglyNumber(7) << endl;
    cout << theKUglyNumber(8) << endl;
    cout << theKUglyNumber(9) << endl;
    cout << theKUglyNumber(10) << endl;
    cout << theKUglyNumber(1499) << endl;
    cout << theKUglyNumber(1500) << endl;
    cout << theKUglyNumber(1501) << endl;
     
    return 0;
}
