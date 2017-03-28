//
//  main.cpp
//  jz03_FindInParticallySoftedMatrix_p38Second
//
//  Created by kqy on 28/03/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
#define columns 4
#define rows 4
#warning todo: *matrix,还要写后边的[][4]吗？
void displayMatrix(int  *matrix, int row, int column) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j ) {
            cout<< *(matrix + i * row + j) << "  ";
        }
        cout << endl;
    }
}

void findNumberInMatrix(int  *matrix, int row, int column, int target) {
    int i = 0;
    int j = column -1;
    while (i < row && j >= 0) {
        int change =*(matrix + i * row + j);
        if (target ==  *(matrix + i * row + j)) {
            cout << "find in" << i + 1 << "row. " << j + 1 << "columns" << endl;
            return ;
        } else if(target >  *(matrix + i * row + j)) {
            ++i;
        } else {
            --j;
        }
    }// while
}
void test01() {
//    int array[rows][columns] = {{1,2,3,4}, {2,3,4,5},{3,5,7,9}, {5,10,12, 15}};
//        int array[rows][columns] = {[1,2,3,4], [2,3,4,5], [3,5,7,9],  [5,10,12, 15]};
       int array[4][4] = {{1,2,3,4}, {2,3,4,5},{3,5,7,9}, {5,10,12, 15}};
    displayMatrix((int*)array, 4, 4);
    findNumberInMatrix((int *)array,4, 4, 10);
}
int main(int argc, const char * argv[]) {
    test01();
    return 0;
}
