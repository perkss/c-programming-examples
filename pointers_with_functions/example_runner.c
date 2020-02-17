#include <stdio.h>
#include <stdlib.h>
#include "swap.h" // use speech marks for local files and <> for standard libraries
#include "return_pointers.h"
#include "helpers.h"

void passAndCallBy();

void returningPointers();

// gcc -o runner example_runner.c swap.c return_pointers.c helpers.c
int main() {

    passAndCallBy();
    returningPointers();

}

void passAndCallBy() {
    int a = 10;
    int b = 7;
    printf("** Pass by Reference and Value **\n");

    printf("a = %d b = %d\n", a, b);

    printf("Swapping by value wont impact originals\n");

    swapPassByValue(a, b);

    printf("a = %d b = %d \n", a, b);

    printf("Swapping by reference will impact originals\n");

    swapPassByReference(&a, &b);

    printf("a = %d b = %d\n", a, b);
}

void returningPointers() {
    printf("** Returning Pointers **\n");

    int *arr;
    int size = 10;

    arr = allocateArray(arr, size, 0);

    printArray(arr, size);

    free(arr);

    // Simply manipulate the provided allocated array to be populated
    int *arr2 = NULL;
    voidAllocateArray(&arr2, size, 33);

    printArray(arr2, size);

    free(arr2);

}