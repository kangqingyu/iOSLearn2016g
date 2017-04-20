#include <iostream>
void reOrderOddEven(int *array, unsigned int length) {
    int *front = array;
    int *back = array + length -1 ;
    while(front < back) {
        while((*front &0x1) == 1) ++ front;
        while((*back &0x1) == 0) -- back;
        if (front < back) {
        *front = *front + *back;
        *back = *front - *back;
        *front = *front - *back;
        }
        ++front;
        -- back;
    }  
}
void displayArray(int *array, int length) {
    for (int i = 0; i < length; ++i) std::cout << array[i] << "  ";
    std::cout << std::endl;
}
int main() {
    int array1[11] = {3, 9, 7, 5, 4, 12, 54, 89, 15, 28};
    reOrderOddEven(array1, 10);
    displayArray(array1, 10);
    return 0;
}
