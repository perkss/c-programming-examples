#include "swap.h"
#include <stdio.h>

void swapPassByReference(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    printf("Local/Automatic variables swapped a = %d b = %d\n", *a, *b);
}

void swapPassByValue(int a, int b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    printf("Local/Automatic variables swapped a = %d b = %d\n", a, b);
}



