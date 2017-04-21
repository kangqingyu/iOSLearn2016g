#include <iostream>
using namespace std;
void shellSort(int *array, int length) {
    for (int step = length >> 1; step >0 ; step /= 2) {
	for (int i = step + 1; i < length; i += step) {
	    int j;
	    if (array[i] < array[i -step]) {
		array[0] = array[i];
		for (j = i - step; array[j] > array[0]; j -= step) {
		    array[j+step] = array[j];
		}// for
	    array[j+step] = array[0];
	    }// if
	}// for
    }//for
		    
	    
}
int main(int argc, const char * argv[]) {
    int array1[10] = {99, 3, 8, 4, 12, 34, 5, 28, 11, 7};
    shellSort(array1, 10);
    for (int i = 0; i < 10; ++i) cout << array1[i] << " ";
    cout << std::endl;
    return 0;
}
