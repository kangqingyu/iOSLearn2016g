//
//  main.cpp
//  jz08_MinNumberInRotatedArray_p66Second
//
//  Created by kqy on 31/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
void autoCreateRotateArray(int  *strHead, int location, int length) {
    int startNumber = length - location + 2;
    int *pStart = strHead;
    int i;
    for ( i = 0; i < location; ++i) {
        *(pStart + i) = startNumber ++;
    }
    int j = 1;
    for (i = location - 1; i < length; ++i ) {
        *(pStart + i) = j++;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...               
    int  str1[100] = {0};
    autoCreateRotateArray(str1, 4, 8);
//        int x= strlen(str1);
//int y =     strlen(&str1);
//    str1.leng
    for (int i = 0; i < 8 ; ++i) {
        cout << str1[i] << "  ";
    }
    cout << endl;
    cout << "find 1 in: " << find1RotatedArray(str1, 8);
    return 0;
}
int  find1RotatedArray0(int *strHead, int length) {
    int *pHead = strHead;
    int low = 0;
    int high = length - 1;
    //    int middle = (low + high) / 2;
    int middle = 0;
    while (low < high) {
        if (*(pHead + middle) == 1) {
            return middle + 1;
        } else if(*(pHead + low) < *(pHead + middle)) {
            low = middle;
            middle = (low + high) / 2;
        } else {
            high = middle;
            middle = (low + high) / 2 ;
        }
    }
    return 0;
}
