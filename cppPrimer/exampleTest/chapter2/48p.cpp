#include <iostream>
using namespace std;
int main() {
   int i = 10;
   int *p = &i;
   int &ref = *p;
   ref = 8;
   cout << ref << endl ;
   int *p1 = nullptr;
   int *p2 = 0;
   int *p3 = NULL;
   cout << "address: " << p1 << " - " << p2 << " ;" << p3 <<  endl;
   
   return 0;
}
