#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "return_pointers.h"


// Return the pointer
int *allocateArray(int *arr, int size, int value) {
    arr = (int *) malloc(size * sizeof(int)); // this can be done with Realloc if single default value
    if (arr != NULL) {
        for (int i = 0; i < size; i++) {
            arr[i] = value;
        }
    }
    return arr;
}

void voidAllocateArray(int **arr, int size, int value) {
    *arr = (int *) malloc(size * sizeof(int));
    if (*arr != NULL) {
        for (int i = 0; i < size; i++) {
            *(*arr + i) = value;
        }
    }
}