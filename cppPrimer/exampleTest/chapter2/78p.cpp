#include <iostream>
using namespace std;
int main() {
/*
    string word;
    while (cin >> word) {
        cout << word << "  " << ";";
    }
    cout << endl;
*/
   string line;
   while(getline(cin, line)) {
        if (line.empty()) continue;
	cout << line << ";" << endl;
	}
   return 0;
}
