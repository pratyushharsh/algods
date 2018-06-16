//
// Created by Pratyush Harsh on 6/15/2018.
//


#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* insertionSort(int arr[], int size) {
    int counter = 1;
    while(counter) {
        counter = 0;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                counter++;
            }
        }
    }

    return arr;
}



void printArray(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
