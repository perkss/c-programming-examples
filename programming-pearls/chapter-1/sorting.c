/**
An example of an in memory sort of numbers in C using the
standard library quick sort
*/

#include <stdio.h>
#include <stdlib.h>

int comparison(int *x, int *y) {
  return *x - *y;
}

// hold the bitset
int a[10000000];

int main(void) {
  int i, n = 0;
  printf("Please enter the numbers. Once done press (ctrl d) for UNIX or (ctrl z) for Windows\n");
  while(scanf("%d", &a[n]) != EOF)
          n++;

  qsort(a, n, sizeof(int), comparison);

  printf("Sorted input\n");
  for (i = 0; i < n; i++)
          printf("%d\n", a[i]);

  return 0;
}
