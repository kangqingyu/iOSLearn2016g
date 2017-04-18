#include <iostream>
int Fibonacci01(int target) {
    int array[2] = {0, 1};
    if (target < 0 ) {
    return -1;
    } else if (target < 2) {
    return array[target];
    }
    return Fibonacci01(target -1) + Fibonacci01(target - 2);
}
int Fibonacci02(int target) {
    int first = 0;
    int second = 1;
    int index = 2;
    int temp;
    int array[2] = {0, 1};
    if (target < 0 ) {
    return -1;
    } else if (target < 2) {
    return array[target];
    }
    while(index < target) {
    ++ index;
    temp = first + second;
    first = second;
    second = temp;
    } 
    return first + second;
    
}
int main(int argc, const char *argv[]) {
    std::cout << Fibonacci02(-1);   
    std::cout << Fibonacci02(1);   
    std::cout << Fibonacci02(0);   
    std::cout << Fibonacci02(4);   
    return 0;
}
