// Best Use: If items in array are random

#include <iostream>
using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int pivot(int arr[], int pivotIndex, int endIndex) {
    int swapIndex = pivotIndex;
    for(int i= pivotIndex; i <= endIndex; i++) {
        if(arr[i] < arr[pivotIndex]) {
            swapIndex ++;
            swap(arr, swapIndex, i);
        }
    }
    swap(arr, pivotIndex, swapIndex);
    return swapIndex;
}

void quickSort(int arr[], int leftIndex, int rightIndex) {
    if(leftIndex >= rightIndex) return;
    int pivotIndex = pivot(arr, leftIndex, rightIndex);
    quickSort(arr, leftIndex, pivotIndex-1);
    quickSort(arr, pivotIndex+1, rightIndex);

}

int main() {
    int arr[] = {4,6,1,7,3,2,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, size-1);

    for(auto i : arr){
        cout << i << " ";
    }
}