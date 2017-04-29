#include <iostream>
using namespace std; 
void display(int *array, int length) {
    for (int i = 0; i < length; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
int param(int *array, int low, int high) {
    int pivot = array[high];   
    int small = -1;
    int temp;
    for (int index = low; index < high; ++index) {
	if(array[index] < pivot) {
	++small;
	    if(small != index) {
		temp = array[small] ;
		array[small] = array[index];
		array[index] = temp;
	    }
	}
    }
    ++small;
    temp = array[small];
    array[small] = array[high];
    array[high] = temp;
    return small;
}
void quickSort(int *array, int low, int high) {
    int pivot = param(array, low, high);  
    quickSort(array, low, pivot -1);
    quickSort(array, pivot + 1, high);
}
int main(int argc, const char* argv[]) {
    int array[10] = {3, 23, 5, 28, 98, 35, 9, 12, 58};
    quickSort(array,0,  9);
    display(array, 9);
    return 0;
}
