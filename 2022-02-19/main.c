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
  return ((x & ~0<<n) | getbits(y, p, n));
}

/* invert: return x with n bits that begin at position p inverted */
unsigned invert(unsigned x, int p, int n)
{
  return setbits(x, p, n, ~getbits(x, p, n));
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

int main()
{
  if (invertTest() == 0) {
    printf("invertTest passed");
  } else {
    printf("invertTest() failed");
  }
}
