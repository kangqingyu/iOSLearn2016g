#include <iostream>
using namespace std;
void strPermutation(char *str, int index) {
    if(str[index] == '\0') cout << str << "  ";
    for(int i = 0; i < index; ++i) {
        
    
}
int main(int argc, const char *argv[]) {
    char *str = "abc";
    strPermutation(str);
    return 0;
}
