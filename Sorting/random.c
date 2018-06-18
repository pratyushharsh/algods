#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void generateRandomIntArray(int a[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand()%10000;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }
}
