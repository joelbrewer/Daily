#include <stdio.h>

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
  int b;

  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}

int betterBitcount(unsigned x)
{
  int b = 0;
  while (x != 0) {
    x &= x-1;
    b++;
  }
  return b;
}

// To get the two's complement:
//  1. Write the number in binary
//  2. Invert the digits.
//  3. Add one to the result.
//  
//  Eg: To get -16 in two's complement:
//
//  Write 16 in binary:
//
//  0 0 0 1 0 0 0 0 
//
//  Invert the digits:
//
//  1 1 1 0 1 1 1 1
//
//  Add one:
//
//  1 1 1 1 0 0 0 0
//  
//  NOTES:
//
//  - A leading 1 means the number is negative
//  - A leading 0 means the number is 0 or positive
//  - See: https://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html

int main()
{
  printf("1s in 16: %d\n", bitcount(16)); // should return 1
  printf("1s in 16: %d\n", bitcount(17)); // should return 2
  // Why does x &= (x-1) delete the rightmost 1-bit in x? (in a two's complement number system)
  unsigned x = 15;
  x &= (x-1);
  printf("x : %d\n", x);
  x &= (x-1);
  printf("x : %d\n", x);
  x &= (x-1);
  printf("x : %d\n", x);
  x &= (x-1);
  printf("x : %d\n", x);

  printf("1s in 1111 (15) %d", betterBitcount(15));

  // &= (x-1) is equivalent to:
  // x = x & (x-1)
  //
  //    1111 (x)
  //   &1110 (x-1)
  //   -----
  //    1110
  //
  //    1110 (x)
  //   &1101 (x-1)
  //   -----
  //    1100
  //
  //
  //
}
