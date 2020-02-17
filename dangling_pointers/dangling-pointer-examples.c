#include <stdlib.h>
#include <stdio.h>

int main() {
    // Define the pointer
    int *p1 = (int *) malloc(sizeof(int));

    *p1 = 7;

    printf("Value of *p1 is %d with address %p\n", *p1, p1);

    int *p2;
    p2 = p1;

    printf("Value of *p1 is %d and *p2 is %d\n", *p1, *p2);

    free(p1);

    // as p2 is a pointer alias to p1 then its data has been freed already.

    // if we attempt to do any operation on p2 then we have no control over what would happen. Bad!!

    printf("Value of *p1 is %d and should be rubbish due to free called and *p2 is rubbish also %d.\nAlthough very likely to keep original values.\n",
           *p1,
           *p2);


    *p2 = 10;

    printf("Value of *p2 is %d is still rubbish\n", *p2);

    int *p3 = (int *) malloc(sizeof(int));

    *p3 = 10;

    printf("Value of *p1 is %d and *p2 is %d and *p3 is %d.\nPotentially the memory of p1,p2 is now overwritten by p3.",
           *p1, *p2, *p3);

    free(p3);
}

