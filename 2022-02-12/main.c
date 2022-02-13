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

int main() {
  printf("Hello World\n");
  unsigned int a = 60; /* 0011 1100 */
  unsigned int b = 13; /* 0000 1101 */
  int c = 0;

  c = a & b;           /* 0000 1100 = 12  */
  c = a | b;           /* 0011 1101 = 61  */
  c = a ^ b;           /* 0011 0001 = 49  */
  c = a << 2;          /* 1111 0000 = 240 */
  c = a >> 2;          /* 0000 1111 = 15  */
  c = ~a;              /* 1100 0011 =  */

  printf("%d\n", getbits(b, 3, 4));
  decToBinary(getbits(b, 3, 4));
  decToBinary(~0);
};
