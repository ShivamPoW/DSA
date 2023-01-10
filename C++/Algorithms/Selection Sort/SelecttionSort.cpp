#include <iostream>

using namespace std;

void selectionSort(int array[], int size) {
    for(int i=0; i < size; i++){
        int minIndex = i;
        for(int j=i+1; j <size; j++){
            if(array[minIndex] > array[j]) {
                minIndex = j;
            }
        }
        if(i != minIndex) {
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
        }
    }
}

int main() {
    int arr[] = {3, 5, 6, 7, 2, 1};
    int size = sizeof(arr)/sizeof(arr[1]);

    selectionSort(arr, size);

    for(auto val : arr) {
        cout << val << endl;
    }
}