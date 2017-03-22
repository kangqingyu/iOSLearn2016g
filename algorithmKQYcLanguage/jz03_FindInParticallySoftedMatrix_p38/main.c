//
//  main.c
//  jz03_FindInParticallySoftedMatrix_p38
//
//  Created by kqy on 21/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <stdio.h>
#define lineNumber 4
#define rowNumber 4
void createMatrixAuto(int matrix[][4],int count){
    int i, j;
    for (i = 0; i < count; ++ i ) {
        for (j = 0; j < count; ++j ) {
            matrix[i][j] = i * 2 + j;
        }
    }
}
void displayMatrix01(int *matrix ,int  count) {
    int i,j;
    int *p = matrix;
    for (i = 0; i < count; ++ i ) {
        for (j = 0; j < count; ++j ) {
//            printf("%2d  ", matrix[i][j]);
//            printf("%2d", matrix[j*4 + i]);
            printf("%2d", *(p + j*4 +i));
            printf("%2d", *(matrix + j*4 +i));
        }
        printf("\n");
    }
}
//void displayMatrix(int *matrix ,int  count) {
//    int i,j;
//    int *p = matrix;
//    for (i = 0; i < count; ++ i ) {
//        for (j = 0; j < count; ++j ) {
////            printf("%2d  ", matrix[i][j]);
//            printf("%2d", *(i*count + j));
//        }
//        printf("\n");
//    }
//}
void findNumber(int matrix[][4],int columns, int target) {
    int i ,j;
    int flag = 0;//// flag =0 没有找到
    j = columns -1;
    i = 0; //从右上角开始
    while (j  >= 0 || i < columns) {
        if (matrix[i][j] == target) {
            printf("find: %d line, %d row\n", i+1, j+1);
            flag = 1;// flag =1 找到了，跳出去。
            break;
        } else if(matrix[i][j] < target) {
            ++i;
        } else if(matrix[i][j] > target) {
            --j ;
        }
        if (flag) {
            break;
        }// flag =1 找到了，跳出去。
    }//while
    if (!flag) {
        printf("can't find\n");
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int matrix[lineNumber][lineNumber] = {};
    createMatrixAuto(matrix , lineNumber);
    displayMatrix01(matrix , lineNumber) ;
    findNumber(matrix, lineNumber, 5);
    return 0;
}
