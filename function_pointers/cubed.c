#include <stdio.h>
#include <stdlib.h>


int cubed(int n);

int multiply(int a, int b);

int divide(int a, int b);

typedef int (*fptrOperation)(int, int);

// Pass the function pointer as a first argument
int compute(fptrOperation operation, int num1, int num2);

// Function pointer definition
int (*fptr1)(int);

// Commonly typedef are used for function pointer definitions
typedef int (*funcptr)(int);


/*
 * Returning a function pointer example
 */
fptrOperation select(char opcode) {
    switch (opcode) {
        case '*':
            return multiply;
        case '/':
            return divide;
        default:
            exit(-1);
    }
}

int evaluate(char opcode, int num1, int num2) {
    fptrOperation operation = select(opcode);
    return operation(num1, num2);
}

int main() {

    int n = 2;
    // Function pointer is assigned to the function cubed
    fptr1 = cubed;
    printf("%d cubed is %d\n", n, fptr1(n));

    funcptr fptr2;
    fptr2 = cubed;
    printf("%d cubed is %d\n", n, fptr2(n));

    printf("Function pointers passed as arguments to functions\n");

    printf("Computing multiply %d\n", compute(multiply, 5, 2));

    printf("Function pointers returned from functions\n");

    printf("%d\n", evaluate('*', 5, 6));
    printf("%d\n", evaluate('/', 12, 6));

}

int cubed(int n) {
    return n * n * n;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b > 0)
        return a / b;
    else
        exit(-1);
}

int compute(fptrOperation operation, int num1, int num2) {
    return operation(num1, num2);
}

