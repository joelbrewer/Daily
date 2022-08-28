#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
void doubling(int x);
void doubling2(int *x);

int main (void) {
  printf("Hello world\n");
  int x = 2;
  int *y = &x;

  doubling(x);
  doubling2(y);
  printf("x %d\n", x);
  printf("y %d\n", *y);
  return 0;
}

void doubling(int x)
{
  x = x * 2;
  printf("x : %d\n", x);
}

void doubling2(int *x)
{
  (*x) = (*x) * 2;
  printf("x : %d\n", x);
}
