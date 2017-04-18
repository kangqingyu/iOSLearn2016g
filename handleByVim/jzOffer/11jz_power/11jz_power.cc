#include <iostream>
double powerWithUnsigned(unsigned, int) ;
double power(double base, int exponent) {
    if (base <= 0) return -1;
    if (exponent == 0) return 1;
    double result = 0;
    if (exponent < 0) {
    result = powerWithUnsigned(base, -exponent) ;
    return 1.0 / result;
    } else {
    return powerWithUnsigned(base, exponent);
    }
}
double powerWithUnsigned(unsigned base, int exponent) {
    if(exponent == 0)  return 1;
    if(exponent == 1) return base;
    double result; 
    result = powerWithUnsigned(base, exponent >> 1) ;
    result *= result;
    if ((exponent & 0x1) == 1 ) result *= base;
    return result;
}
int main(int argc, const char *argv[]) {
    std::cout << power(3, 2) << std::endl;
    std::cout << power(4, 2) << std::endl;
    std::cout << power(-3, 2) << std::endl;
    std::cout << power(3, -2) << std::endl;
    return 0;
}
