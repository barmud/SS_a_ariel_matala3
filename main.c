#include <stdio.h>
#include "isort.h"
#define LEN(X) (sizeof(X)/sizeof(*X))
#define N 50
#define LINE 256


int main() {

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &(*(arr+i)));
    }
    insertion_sort(arr, N);
    printArray(arr,N);
}













