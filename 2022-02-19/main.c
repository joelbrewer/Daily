#include <stdio.h>


/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}

/* decToBinary: print binary representation of int n */
void decToBinary(int n)
{
  printf("\n");
  for(int i = 31; i >= 0; i--) {
    int k = n >> i;
    if (k & 1)
      printf("1");
    else
      printf("0");
  }
}

/* setbits: return x with the n bits that begin at position p set to the rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  return (x & ~(~(~0 << n) << (p+1-n)))
    | ((y & ~(~0 << n)) << (p+1-n));
}

/* invert: return x with n bits that begin at position p inverted */
unsigned invert(unsigned x, int p, int n)
{
  return setbits(x, p, n, ~getbits(x, p, n));
}

/* rightrot: returns the value of the integer x rotated to the right by n bit positions */
/* NOTE: Assumes 8bit integers */
unsigned rightrot(unsigned x, int n)
{
  if (n == 0) {
    return x;
  } else {
    int frontBit = getbits(x, 0, 1);
    int shifted = x >> 1;
    int rotated = setbits(shifted, 7, 1, frontBit);
    return rightrot(rotated, n-1);
  }
}

int invertTest()
{
  unsigned int a = 60; /* 0011 1100 */
  unsigned int b = invert(a, 3, 4); /* should return 0011 0011 (51) */
  if (b == 51) {
    return 0;
  }
  return 1;
}

int rightrotTest()
{
  unsigned int a = 60; /* 0011 1100 */

  if (rightrot(a, 1) != 30) { /* should return 0001 1110 (30) */
    return 1;
  }
  
  if (rightrot(a, 3) != 135) { /* should return 1000 0111 (135) */
    return 1;
  }

  if (rightrot(a, 8) != 60) { /* should return 0011 1100 (60) */
    return 1;
  }

  if (rightrot(a,9) != 30) { /* should return 0001 1110 (60) */
    return 1;
  }

  return 0;
}

int main()
{
  printf("\n");
  printf("invertTest: %d\n", invertTest());
  printf("rightrotTest: %d\n", rightrotTest());
     
}
