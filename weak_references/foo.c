#include <stdio.h>

void f(void);

int x = 12421;
// In global variables they can be strong references where they are initialized and functions are strong
// Weak one are global variables not initialized
// Three rules for deciding
// 1) Multiple strong not allowed
// 2) Strong symbol and multiple weak symbols choose the strong
// 3) multiple weak choose any of them

// This case bar.c defines x again and it overwrites it. f() is called that redefines x and then overwrites y also
// due to next in memory usually.
int y = 5552;

int main() {
    f();
    printf("x = %d y = %d \n", x, y);
    return 0;
}

// TO Run
// gcc -o foobar foo.c bar.c
