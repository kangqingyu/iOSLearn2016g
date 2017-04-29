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
    int small = low-1;
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
int param02(int *array, int low, int high) {
    int pivot = array[low];   
    while(low < high) {
    	while(array[high] > pivot && low < high) --high;
	array[low] = array[high];
	while(array[low] < pivot && low < high) ++low;
	array[high] = array[low];
    }
    array[low] = pivot;
    return low;
}
void quickSort(int *array, int low, int high) {
    if(low >= high) return;
    int pivot = param02(array, low, high);  
    quickSort(array, low, pivot -1);
    quickSort(array, pivot + 1, high);
}
int main(int argc, const char* argv[]) {
    int array[10] = {3, 23, 5, 28, 98, 35, 9, 12, 58};
    quickSort(array,0,  9);
    display(array, 9);
    return 0;
}
