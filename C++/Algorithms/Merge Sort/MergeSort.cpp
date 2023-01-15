#include <iostream>

using namespace std;

void merge(int arr[], int leftIndex, int midIndex, int rightIndex) {
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for(int i=0; i<leftArraySize; i++) {
        leftArray[i] = arr[leftIndex + i];
    }

    for(int j=0; j <rightArraySize; j++) {
        rightArray[j] = arr[midIndex + 1 + j];
    }

    int index =  leftIndex;
    int i = 0;
    int j = 0;

    while (i < leftArraySize && j < rightArraySize) {
        if(leftArray[i] <= rightArray[j]) {
            arr[index] = leftArray[i];
            index++;
            i++;
        }else{
            arr[index] = rightArray[j];
            index++;
            j++;
        }
    }

    while(i < leftArraySize) {
        arr[index] = leftArray[i];
        index++;
        i++;
    }

    while(j < rightArraySize) {
        arr[index] = rightArray[j];
        index++;
        j++;
    }
}

// Recursion
void mergeSort(int arr[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex) return;
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;  
    mergeSort(arr, leftIndex, midIndex);
    merge(arr, leftIndex, midIndex, rightIndex);
}


int main() {

    int arr[] = {1,3,7,8,2,4,5,6};

    int size = sizeof(arr)/sizeof(arr[0]);
    int leftIndex = 0;
    int rightIndex = size-1;

    mergeSort(arr, leftIndex, rightIndex);

    for(auto i: arr) {
        cout << i << " ";
    }
}