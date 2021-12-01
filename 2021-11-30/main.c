#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"

int setBits(int x, int p, int n, int y);

int main()
{
  int x, p, n, y, output;
  // printf("Input : %d\n", s1);
  output = setBits(x, p, n, y);
  printf("Output : %d\n", output);
  return 0;
}

/* setBits: returns x with the n bits that begin at position p
 * set to the rightmost n bits of y, leaving the other bits
 * unchanged
 *
 * Example:
 * x = 10000
 * p = 2 (position 0 is at the right end)
 * n = 2
 * y = 11111
 *
 * out = setBits(x, p, n, y)
 * out = 10110
 *
 * Probably need to use a mask and "&" operator to accomplish this 
 */

int setBits(int x, int p, int n, int y)
{
}
