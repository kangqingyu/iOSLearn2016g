#include <iostream>
int findInMatrix(int **matrix, int row, int columns, int target) {
    int *p = *matrix;
    int i = 0;
    int j = columns - 1; 
    while(i < row && j >= 0) {
       if (*(*matrix + i + j * columns) == target) {
       std::cout << "row:" << i + 1 << "columns:" << j + 1 << std::endl;
       return 1;
       } else if (*(*matrix + i + j * columns) > target) --j;
        else ++ i;
       
    }
    return -3;
}

int main(int argc, const char *argv[]) {
    int row = 4;
    int columns = 3;
    int **array = new int*[row];
    for (int i = 0; i < row; ++i) {
        array[i] = new int [columns];
        for (int j = 0; j < columns; ++j) {
        array[i][j] = i * columns + j;
        }
    }
    for (int i = 0; i < row; ++i ) {
        for (int j = 0; j < columns; ++j) {
        //std::cout << *(*array + j + i * columns) << "  ";
        std::cout << array[i][j] << "  ";
        }
       std::cout << std::endl;
    }
    std::cout << findInMatrix(array, row, columns, 5);
    return 0;
}

