//
//  main.c
//  jz08_MinNumberInRotatedArray
//
//  Created by kqy on 23/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <stdio.h>
//myMiddle,旋转数组转折的数字：比如5，就是把数字1从index=5开始，前4个数是最大的4个
void createRotatedArray(int *sortedArray, int length, int  myMiddle) {
    int *p = sortedArray;
//    int backNumber;//1开始有多少个数字在数组后边
//    backNumber = length - myMiddle + 1;
    int frontNumber;
    frontNumber = length - myMiddle + 1;//第一位数字是多少。
    int start = 1;//数组从1开始。
    //设置前边的数
    for (int i = 0; i < myMiddle; ++i) {
//        p[i] =frontNumber ++;
        *p = frontNumber ++;
        ++p;
    }
    //设置后边的数
   
    int i = 1;
    int backCount = length -myMiddle;
    while (i <= backCount)  {
        *p = i ++;
        p++;
    }
   *p = '\0';
}
void displayArray(int  *array) {
    int *p = array;
    while (*p) {
//        putchar(*p);
        printf("%d  ", *p);
        ++p;
    }
}
void findMinNumber(int *array, int length) {
    int target = 1;//现在是找1，如果是其他，可以作为参数传进来。
    int low = 0;
    int high = length - 1;
    int flag = 0;//找到为1；
    int middle = (low + high) / 2;
//    while (middle != low && middle != high  && (!flag) ) {
    while (low < high && (!flag)) {
        if (array[middle] == target) {
            printf("find target at %d", middle);
            flag = 1;
        }
        else if (array[middle] < target) {
            high = middle;
            middle = (low + high) / 2;
        } else {
            low =  middle;
            middle = (low + high) / 2;
        }// else
    }// while
    if (!flag) {
        printf(" can't find");
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int array[100];
    createRotatedArray(array , 10, 7);
    displayArray(array);
    findMinNumber(array, 10);
    return 0;
}
