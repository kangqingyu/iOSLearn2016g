#include <iostream>
using namespace std;       
void printCircle(int **numbers, int start, int row, int column) {
    int endRow = row - 1 - start;
    int endColumn = column - 1 - start;
    int i, j;
    for (j = start; j <= endColumn; ++j) cout << numbers[start][j] << " ";
    cout << endl;
    for (i = start + 1; i <= endRow && endRow > start; ++ i) cout << numbers[i][endColumn] << " ";
    cout << endl;
    for (j = endColumn - 1; j >= start && endColumn > start + 1; -- j) cout << numbers[endRow][j] << " ";
    cout << endl;
    for (i = endRow - 1; i > start && endRow > start + 2; -- i) cout << numbers[i][start] << " ";
   cout << endl;
}
void PrintMatrixCloseWisely(int **numbers, int row, int column) {
    int start = 0;
    while(row > start * 2 && column > 2 * start) {
    printCircle(numbers,  start, row, column);
    ++ start;
    }
}
int main(int argc, const char *argv[]) {
    int row = 4;
    int column = 5;
    int **numbers = new int*[row];  
    for (int i = 0 ; i < row; ++i) {
        numbers[i] = new int[column];
        for (int j = 0; j < column; ++j) {
	numbers[i][j] = i + j * column;
        cout << numbers[i][j] << " ";
        }
        cout << endl;
    }
    PrintMatrixCloseWisely(numbers, row, column);
    return 0;
}
