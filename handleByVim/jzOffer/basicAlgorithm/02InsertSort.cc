#include <iostream>
using namespace std;
void insertSort(int *array, int length) {
    for (int i = 1; i < length; ++i) {
        if(array[i] < array[i-1]) {
            array[0] = array[i];
            int step;
            for(step = i- 1; step > 0; -- step) {
            if(array[step] < array[0]) break;
            array[step + 1] = array[step];
            }// for
            array[++step] = array[0];
        }// if
    }// for
    
}
int main(int argc, const char *argv[]) {
    int array[11] = {0, 3, 2, 12, 28, 89, 5, 38, 11, 10};
    insertSort(array, 10);
    for (int i = 0; i < 10; ++i) {
       cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
