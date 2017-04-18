#include <iostream>
using namespace std;
void numberOf1(int number) {
    int count = 0;
    int compact = 1;
    while(number) {
    if (number & compact)       count++;
    number = number >> 1;
    }
    cout << " 1     " << count << endl;
}
void numberOf1InB02(int number) {
    int count  = 0;
    while(number) {
    number = (number -1 ) & number;
    ++ count ;
   }
   cout << "method2: " << count << endl;
}
int main(int argc, const char *argv[]) {
    numberOf1(3);
    numberOf1InB02(3);
    numberOf1(23);
    numberOf1InB02(23);
    numberOf1(2);
    numberOf1InB02(2);
    numberOf1(8);
    numberOf1InB02(8);
    
    return 0; 
}  

