//
//  main.c
//  alg_BinarySearch223wd
//
//  Created by kqy on 23/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <stdio.h>
typedef struct {
    int element[100];
    int length;
}List;
List init(List listEle, int length) {
    listEle.length = length;
    int i;
    for(i = 1; i < length +1; ++i) {
        listEle.element[i] = i*2;
    }
    return listEle;
}
int binarySearch(List listEle, int target) {
    int start =1;
    int end = listEle.length;
    int middle = (1 + end) / 2;
    while (end - start >1) {
        if (listEle.element[middle] == target) {
            printf("find:%d at %d\n", target, middle);
            return middle;
        } else if(listEle.element[middle] > target) {
            end = middle;
            middle = (start + end) / 2;
        } else {
            start = middle;
            middle = (start + end) / 2;
//            return 0;
        }
    }
    printf("can't find\n");
    return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello,alg_BinarySearch223wd World!\n");
    List ListEle;
    ListEle = init(ListEle, 6);
    int targerLoc = binarySearch(ListEle, 7);
    return 0;
}
