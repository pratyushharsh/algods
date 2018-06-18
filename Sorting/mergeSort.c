#include "random.c"
#include <stdio.h>


void merge(int arr[], int l, int m, int r) {

   int n1 = m-l+1;
   int n2 = r-m;

    // Declare two empty array
   int L[n1]; int R[n2];

   int i, j, k;

    // Copy data from the array
   for(i = 0; i < n1; i++) {
       L[i] = arr[l+i];
   }

   for(j = 0; j < n2; j++) {
       R[j] = arr[m+j+1];
   }

   i = 0;
   j = 0;
   k = l;

   while(i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
   }

   // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k++] = R[j++];
    }

}

void mergeSort(int *a, int p, int q) {

    if(p >= q){
        return;
    }
    // 1. Divide
    int mid = (p+q)/2;

    // 2. Sort
    mergeSort(a, p, mid);
    mergeSort(a, mid+1, q);

    // 3. Merge
    merge(a, p, mid, q);
}

int main() {
    int n;
    printf("Enter the number of element to be sorted - ");
    scanf("%d", &n);
    int a[n];
    generateRandomIntArray(a, n);
    printArray(a, n);

    mergeSort(a, 0, n-1);
    printf("\nSorted array is\n");
    printArray(a, n);

    return 0;
}
