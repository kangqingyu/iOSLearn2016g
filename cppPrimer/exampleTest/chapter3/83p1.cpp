#include <iostream>
using namespace std;
int main() {
    //string s1 = "hello, world; can? ok";
    string s1("hello, goTo;.?world!");
    int count = 0;
    for ( int c : s1) {
	if (ispunct(c)) ++ count;
        }
    cout << count << endl;
    return 0;
}
