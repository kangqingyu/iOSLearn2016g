//
//  main.cpp
//  jz20_printMatrix_p127
//
//  Created by kqy on 08/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
#include<cstdio>
#include <iomanip>
using namespace std;
void autoCreateMatrix(int *array, int rows, int columns) {
//    int  array[rows][columns];
    int *arrayP = array;
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
//            arrayP[i][j] = i + j * 2;
//            cout << arrayP[i][j] << "  ";
        }
        cout << endl;
    }
//    return array[rows][columns];
}
void printMatrixInCircle(int **numbers, int start, int rows, int columns) {
    int endX = columns - start -1;
    int endY = rows - start - 1;
    int i, j;
    for (i = start; i <=endX; ++i) {
        cout << numbers[start][i] << "  ";
    }
    for (j = start + 1; j <= endY; ++j) {
        cout << numbers[j][endX] << "  ";
    }
    for (i = endX -1; i >= start && endX > start; -- i) {
        cout << numbers[endY][i] << "  ";
    }
    for (j = endY -1 ; j > start && endY - start > 1; --j) {
        cout << numbers[j][start] << "  ";
    }
}
void printMatrixClockWisely(int **numbers, int rows, int columns) {
    if (columns < 1 || rows < 1) {
        return ;
    }
    int start = 0;
    while (rows > 2 *start && columns > 2 *start) {
        printMatrixInCircle(numbers, start, rows, columns);
        ++ start;
    }
}
int main(int argc, const char * argv[]) {
    int  array1[2][5] = {{1, 2, 3, 4, 5}, {10, 9, 8, 7, 6}};
    int columns = 4;
    int rows = 5;
    int **numbers = new int *[rows];
    for (int i = 0; i < rows; ++i ) {
        numbers[i] = new int [columns];
        for (int j = 0; j  < columns; ++ j) {
            numbers[i][j] = j + 1 + columns * i;
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j ) {
            cout<<setiosflags(ios::left)<<setiosflags(ios::right)<<setw(8)<<numbers[i][j] << "     ";
//            cout << numbers[i][j] << "  ";
        }
        cout << endl;
    }
    printMatrixClockWisely(numbers, rows, columns);
    return 0;
}
