#include <iostream>
using namespace std;
void bubbleSort(int *array, int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = length - 1; j > i ; -- j) {
	    if (array[j] < array[j-1]) {
		array[j] = array[j] + array[j-1];
  		array[j-1] = array[j] - array[j-1];
		array[j] = array[j] - array[j-1];
	    }
        }
    }
}
int main(int argc, const char *argv[]) {
   int array[10] ={9, 3,27, 8, 12, 89, 25, 7, 83, 57};
   bubbleSort(array, 10);
   for(int i = 0; i < 10; ++i) cout << array[i] << " ";
   return 0;
}
