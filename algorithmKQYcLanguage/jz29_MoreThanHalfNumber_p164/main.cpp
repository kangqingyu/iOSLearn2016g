//
//  main.cpp
//  jz29_MoreThanHalfNumber_p164
//
//  Created by kqy on 19/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int chooseMiddleNumber(int *array, int length) {
    int flagNumber = array[0];
    int count = 1;
    for (int i = 1; i < length; ++i) {
        if (!count) {
            flagNumber = array[i++];
            ++count;
        }
        if (array[i] != flagNumber) {
            --count;
        } else ++count;
    }
    return flagNumber;
}
int main(int argc, const char * argv[]) {
    int array[13] = {3, 8, 99, 3, 4, 3, 19, 3, 8, 3, 3, 3};
    int array2[13] = {9, 8, 9, 3, 9, 555, 9, 9, 8, 9, 3, 9};
    int array3[12] = {3, 18, 229, 18, 18 , 111, 3, 18, 18, 18, 18};
    cout << chooseMiddleNumber(array, 12) << " ";
    cout << chooseMiddleNumber(array2, 12)<< " ";
    cout << chooseMiddleNumber(array3, 11)<< " ";

    return 0;
}
int chooseMiddleNumber04(int *array, int length) {
    int tempNumber  = array[0];
    int count = 1;
    for (int i = 1; i < length; ++i) {
        if (array[i] == tempNumber) {
            ++ count;
        } else {
            -- count;
        }
        if (count == 0) {
#warning 可能会越界
            ++i;
            if (i == length) {
                continue;
#warning 跳出2个if的情况。break改成continue?
            }
            tempNumber = array[i];
            count = 1;
        }
    }
    return tempNumber;
}
