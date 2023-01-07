#include <stdio.h>
#include "isort.h"
#define LEN(X) (sizeof(X)/sizeof(*X))
#define N 50
#define LINE 256


/**
 * This method shifts X elements 1 step forward in the given array
 * @param arr integer typed array pointer
 * @param i how many elements to relocate
 */
void shift_element(int* arr, int i){
    while (i >= 0)
    {
        *(arr + i + 1) =  *(arr + i);
        i--;
    }
}

/**
 * This method execute Insertion Sort Algorithm on a given array
 * @param arr an integer typed array pointer
 * @param len the length of the array
 */
void insertion_sort(int* arr , int len) {
    int key, j;
    for (int i = 1; i < len; i++) {
        key = *(arr + i);
        j = i - 1;
        while (*(arr + j) > key && j >= 0) {
            shift_element(arr+j, 0);
            j--;
        }
        *(arr + j + 1) = key;
    }
}

/**
 * This method prints value of a given integer typed array while splitting the values with the character = ','
 * @param arr integer typed array
 * @param n length of the array
 */
void printArray(int* arr, int n){

    for (int i = 0; i < n-1; i++) {
        printf("%d,", *(arr + i));
    }
    printf("%d\n",*(arr+n-1));
}
    


