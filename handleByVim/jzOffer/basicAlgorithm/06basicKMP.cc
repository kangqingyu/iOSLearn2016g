#include <iostream>
using namespace std;
int searchSubStr(char *str, char *subStr) {
    char *pCompare = str;
    char *pSub = subStr;
    char *pStr = pCompare;
    while (*pCompare != '\0') {
        pSub = subStr;
	pStr = pCompare;
	while (*pSub != '\0' && *pStr != '\0') {
    	    if (*pSub != *pStr) break;
            ++pSub;
            ++pStr;
        }
        if (*pSub == '\0' )
    	    return pCompare - str;   
        ++ pCompare;
    }
    return -1;
}
int main(int argc, const char *argv[]) {
   char str[9] = "hellomap";
   char subStr[5] = "ll";  
   cout <<searchSubStr(str, subStr) << " ";
   char subStr2[5] = "el";  
   cout <<searchSubStr(str, subStr2) << " ";
   char subStr3[5] = "hll";  
   cout <<searchSubStr(str, subStr3) << " ";
   char subStr4[5] = "om";  
   cout <<searchSubStr(str, subStr4) << " ";
   return 0;
}
