#include "random.c"
#include <stdio.h>


void merge(int *a, int s, int e) {
    int mid = (s+e)/2;

    int i = s;
    int j = mid+1;
    int k = s;

    int temp[100];

    // Merge the array
    while (i<=mid && j<=e) {
        if(a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    // Add the remaining directly to the temp array
    while (i<=mid) {
        temp[k++] = a[i++];
    }

    while (j<=e) {
        temp[k++] = a[j++];
    }

    // Copy all the element to the original element
    for(int i = s; i < e; i++) {
        a[i] = temp[i];
    }

}

void mergeSort(int *a, int p, int q) {

    if(p>= q){
        return;
    }
    // 1. Divide
    int mid = (p+q)/2;

    // 2. Sort
    mergeSort(a, p, mid);
    mergeSort(a, mid+1, q);

    // 3. Merge
    merge(a, p, q);
}

//int main() {
//    int n;
//    printf("Enter the number of element to be sorted - ");
//    scanf("%d", &n);
//    int a[n];
//    generateRandomIntArray(a, n);
//    printArray(a, n);
//
//    mergeSort(a, 0, n);
//
//    printf("\nSorted array is\n");
//    printArray(a, n);
//
//    return 0;
//}
