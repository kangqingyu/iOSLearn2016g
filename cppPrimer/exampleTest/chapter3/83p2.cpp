#include <iostream>
using namespace std;
int main() {
    string s1("hello?World");  
    for (c : s1) {
	if (islower(c)) toupper(c);
    cout << s1 << endl;
    }
    return 0;
}
