#include <iostream>
using namespace std;
int main() {
   string s5 = "hiya";
   string s6("hiya");
   string s7(10, 'c'); 
   cout << s5 << " " << s6 << " " << s7 << " " << endl;
   string s1, s2;
   cin >> s1 >> s2;
   cout << s1 << "-" << s2 << endl;
   return 0;
}
