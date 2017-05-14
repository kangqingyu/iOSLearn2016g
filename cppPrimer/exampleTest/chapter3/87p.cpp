#include <iostream>
#include <vector>
using namespace std;
void dV(vector<int> v) {
    for (int i : v) cout << i ;
}
int main(int argc, const char *argv[]) {
    vector<int> ivec;
    //vector<vector<int>> v2;
    vector<int> v1(5, 3);
    vector<int> v2(v1);
    vector<int> v3 = v1;
    //cout << v1 << endl << v2 << endl << v3 << endl;
    dV(v1);
    return 0;
}
