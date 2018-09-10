#include <stdio.h>
#include <stdlib.h>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000

int a[1 + N/BITSPERWORD];

//http://www.mathcs.emory.edu/~cheung/Courses/255/Syllabus/1-C-intro/bit-array.html

void set(int i) {
  a[i>>SHIFT] |= (1<<(i & MASK));
}

void clr(int i) {
  a[i>>SHIFT] &= ~(1<<(i & MASK));
}

int test(int i) {
  return a[i>>SHIFT]& (1<<(i & MASK));
}

int main(void) {
  int i;
  printf("Clearing the bit vector.\n");
  for(i = 0; i<N; i++)
    clr(i);
  printf("Enter the values to be sorted. Press ctrl d or ctrl z to stop entering.\n");
  while (scanf("%d", &i) != EOF)
          set(i);
  printf("Printing sorted results.\n");
  for(i = 0; i<N; i++)
    if(test(i))
      printf("%d\n",i);
  return 0;
}
