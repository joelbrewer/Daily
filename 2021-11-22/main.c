#include <stdio.h>
#include <limits.h>
#include <math.h>

void ranges();
void findShortMax();
void findShortMin();
void findCharMax();
void findCharMin();
void findLongMax();
void findLongMin();

int main()
{
  ranges();
  findShortMax();
  findShortMin();
  findCharMax();
  findCharMin();
  findLongMax();
  //findLongMin();
  return 0;
}

void ranges()
{

  printf("\tLow(s)\t\t\tHigh(s)\t\t\tLow(u)\t\tHigh(u)\n");
  printf("char\t%d\t\t\t%d\t\t\t%d\t\t%d\n",SCHAR_MIN, SCHAR_MAX, 0, UCHAR_MAX);
  printf("short\t%d\t\t\t%d\t\t\t%d\t\t%d\n",SHRT_MIN, SHRT_MAX, 0, USHRT_MAX);
  printf("int\t%d\t\t%d\t\t%d\t\t%u\n",INT_MIN, INT_MAX, 0, UINT_MAX);
  printf("long\t%ld\t%ld\t%d\t\t%lu\n",LONG_MIN, LONG_MAX, 0, ULONG_MAX);
  printf("\n");
}

// To find the maximum/minimum value, we keep track of the previous value
// and see if it is equal to he current plur/minus one. When the 
// current value inevitabily overflows, this comparison will fail 
// and we'll have our maximum or minimum value.

void findShortMax()
{
  short i, previ;

  i = 1;
  previ = 0;

  while(previ == i-1) {
    i++;
    previ++;
  }

  printf("Short max : %d\n", previ);
}

void findShortMin()
{
  short i, previ;

  i = -1;
  previ = 0;

  while(previ == i+1) {
    i--;
    previ--;
  }

  printf("Short min : %d\n", previ);
}

void findCharMax()
{
  char i, previ;

  i = 1;
  previ = 0;

  while(previ == i-1) {
    i++;
    previ++;
  }

  printf("Char max : %d\n", previ);
}

void findCharMin()
{
  char i, previ;

  i = -1;
  previ = 0;

  while(previ == i+1) {
    i--;
    previ--;
  }

  printf("Char min : %d\n", previ);
}

// Note: This function is too slow to be practical.
// There's got to be another way to figure this out.
void findLongMax()
{
  long i, previ, prev, exp, start;

  i = 10;
  previ = 1;
  exp = 1;

  printf("previ : %ld\n", previ);
  printf("i : %ld\n", i);
  printf("exp : %ld\n", exp);
  while(previ == (pow(10,exp-1))) {
    previ = i;
    exp++;
    i = pow(10,exp);
  }

  // start = pow(10, exp-2);
  // prev = start-1;
  // while(prev == start-1) {
  //   start++;
  //   prev++;
  // }

  // printf("Long max : %ld\n", prev);
  printf("Long max : %ld\n", previ);
}

void findLongMin()
{
  long i, previ;

  i = -1;
  previ = 0;

  while(previ == i+1) {
    i--;
    previ--;
  }

  printf("Short min : %ld\n", previ);
}

