#include <stdio.h>
#include "helpers.h"

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

