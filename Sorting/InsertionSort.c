//
// Created by Pratyush Harsh on 6/15/2018.
//

#include "random.c"
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int *arr, int size) {
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
}

// Insertion Sort Using Recurssion

void insertionSortRecursion(int arr[], int n) {
    if (n <= 1)
        return;
    insertionSortRecursion(arr, n-1);

    // Insert last elmrnt at its correct place
    int last = arr[n-1];
    int j = n-2;

    while(j >= 0 && arr[j] > last) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}


int main() {
    int n;
    printf("Enter the number of element to be sorted - ");
    scanf("%d", &n);
    int a[n];
    generateRandomIntArray(a, n);
    printArray(a, n);

    insertionSortRecursion(a, n);
    printf("\nSorted array is\n");
    printArray(a, n);

    return 0;
}