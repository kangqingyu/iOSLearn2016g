#include <iostream>
using namespace std;
char * replaceBlank(char *str) {
    char blankCount = 0;
    char *pOrigin = str;
    char *pNew = str;
    while(*pOrigin) {
    if(*pOrigin == ' ') {
        ++ blankCount;
        ++pNew;
        ++pNew;
    }
    ++pOrigin;
    ++pNew;
    }
    *pNew = '\0';
    --pNew;
    --pOrigin;
    while(pOrigin - str > -1) {
    if (*pOrigin != ' ') {
    *pNew = *pOrigin;
    --pNew;
    --pOrigin;
    } else {
    --pOrigin;
    *pNew-- = '0'; 
    *pNew-- = '2';
    *pNew-- = '%';
    -- blankCount;
    }
    }
/*
    if(pNew == pOrigin) return str;
    else {
    while(blankCount --) {
    *pNew -- = '0';
    *pNew -- = '2';
    *pNew -- = '%';
    }
    ++pNew;
    }
*/
    return str;
}
int main(int argc, const char * argv[]) {
    char str[100] = "  hello wor ld ";
//    replaceBlank(str);
    cout << str << endl;
    cout << replaceBlank(str) << endl;
    return 0;
}
