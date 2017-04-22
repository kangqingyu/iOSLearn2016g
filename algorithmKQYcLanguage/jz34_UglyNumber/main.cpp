//
//  main.cpp
//  jz34_UglyNumber
//
//  Created by kqy on 21/04/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
bool isUgly(int number) {
    while (number %2 == 0) number /= 2;
    while (number %3 ==0) number /= 3;
    while (number %5 ==0) number /= 5;
    if (number == 1) {
        return true;
    } else return false;
}
int countUgly(int count) {
    int numbers = 0;
    int index = 0; //丑数的个数
    while (index < count) {
        ++numbers;
        if (isUgly(numbers)) {
            ++index;
        }
    }
    return numbers;
}
int minInThreeNumber(int number1, int number2, int number3) {
    int min = number1 < number2 ? number1 : number2;
    min = min < number3 ? min : number3;
    return min;
}
int getUglyNumber_solution2(int index) {
    int *numbers = new int[index+1];
    numbers[0] = 1;
    int *multiply2 = numbers;
    int *multiply3 = numbers;
    int *multiply5 = numbers;
    int foundCount = 1;
    int min = 1;
    while (foundCount < index) {
        min = minInThreeNumber(*multiply2 * 2, *multiply3 * 3, *multiply5 * 5);
        numbers[foundCount] = min;
        while (*multiply2 * 2 <= min) ++multiply2;
        while (*multiply3 * 3 <= min) ++multiply3;
        while (*multiply5 * 5 <= min) ++multiply5;
        ++foundCount;
    }
    min = numbers[--foundCount];
    delete numbers;
    return min;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "ugly:" << countUgly(122);
    std::cout << std::endl << getUglyNumber_solution2(1500) << std::endl;
    
    return 0;
}
