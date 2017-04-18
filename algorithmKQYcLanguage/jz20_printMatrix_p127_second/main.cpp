//
//  main.cpp
//  jz20_printMatrix_p127_second
//
//  Created by kqy on 17/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
void printMatrix(int **numbers, int row, int column) {
    for (int i = 0 ; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            cout << numbers[i][j] << "  ";
        }
        cout << endl;
    }
}
void printInCircle(int **numbers, int row, int columns, int start) {
    cout << "start !!" << endl;
    int endRow = row - start -1;
    int endColumn = columns - start - 1;
    int moveRow = start + 1;
    int moveColumn = start;
    while (moveColumn <= endColumn) {
        std::cout << numbers[start][moveColumn] << " ";
        moveColumn ++;
    }
    --moveColumn;
    --moveColumn;
    cout << " ------- " << endl;
    while (moveRow <= endRow) {
        std::cout << numbers[moveRow][endColumn] << " ";
        ++moveRow;
    }
    --moveRow;
    --moveRow;
    cout << "        * " << endl;
    while (moveColumn >= start && endRow > start  ) {
        cout << numbers[endRow][moveColumn--] << " ";
    }
    cout << "       # " << endl;
    while (moveRow >start && endRow - start > 1) {
        cout <<numbers[moveRow--][start] << " ";
    }
    cout << "       $ " << endl;

}
void printMatrixClockWisely(int **numbers, int row, int column) {
    if (row < 1 || column < 1) {
        return ;
    }
    int start = 0;
    while (start * 2 < row && column > 2 * start) {
        printInCircle(numbers, row, column, start++);
    }
}
int main(int argc, const char * argv[]) {
    int row = 4;
    int column = 6;
    int **numbers = new int *[row];
    for (int i = 0; i < row; ++i) {
        numbers[i] = new int[column];
        for (int j = 0; j < column ; ++j) {
            numbers[i][j] = i * column + j;
        }
    }
    printMatrix(numbers, row, column);
    printMatrixClockWisely(numbers, row, column);
    return 0;
}
/*4.18找不到错的代码
 void printMatrix(int **numbers, int row, int column) {
 for (int i = 0 ; i < row; ++i) {
 for (int j = 0; j < column; ++j) {
 cout << numbers[i][j] << "  ";
 }
 cout << endl;
 }
 }
 void printInCircle(int **numbers, int row, int columns, int start) {
 int endRow = row - start;
 int endColumn = columns - start;
 int moveRow = start + 1;
 int moveColumn = start;
 while (moveColumn <= endColumn) {
 std::cout << numbers[start][moveColumn] << " ";
 moveColumn ++;
 }
 --moveColumn;
 --moveColumn;
 cout << "       - ";
 while (moveRow <= endRow) {
 std::cout << numbers[moveRow][endColumn] << " ";
 ++moveRow;
 }
 --moveRow;
 --moveRow;
 cout << "        * ";
 while (moveColumn >= start && endColumn > start ) {
 cout << numbers[endRow][moveColumn--] << " ";
 }
 cout << "       # ";
 while (moveRow >start && endRow - start > 1) {
 cout <<numbers[moveRow--][start] << " ";
 }
 cout << "       $ ";
 
 }
 void printMatrixClockWisely(int **numbers, int row, int column) {
 if (row < 1 || column < 1) {
 return ;
 }
 int start = 0;
 while (start * 2 < row && column > 2 * start) {
 printInCircle(numbers, row, column, start++);
 }
 }
 int main(int argc, const char * argv[]) {
 int row = 3;
 int column = 5;
 int **numbers = new int *[row];
 for (int i = 0; i < row; ++i) {
 numbers[i] = new int[column];
 for (int j = 0; j < column ; ++j) {
 numbers[i][j] = i * column + j;
 }
 }
 printMatrix(numbers, row, column);
 printMatrixClockWisely(numbers, row, column);
 return 0;
 }
*/
