#include <stdio.h>
#include <time.h>

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
  int b;

  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low+high) / 2;
    if (x < v[mid]) {
      high = mid - 1;;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1; /* no match */
}

/* betterbinsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int betterbinsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low <= high && x != v[mid]) {
    mid = (low+high) / 2;
    x < v[mid] ? (high = mid -1) : (low = mid + 1);
  }

  return (x == v[mid]) ? mid : -1;
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

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
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
int testLower()
{
  if (lower('A') != 'a') {
    return 1;
  }

  if (lower('a') != 'a') {
    return 1;
  }

  if (lower('B') != 'b') {
    return 1;
  }

  return 0;
}
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

  printf("1s in 1111 (15) %d\n", betterBitcount(15));
  printf("testLower : %d\n", testLower());
  printf("5/2 %d\n", 3/2);

  clock_t t;
  t = clock();
  int sortedArray[1000000] = { 0 };

  for (int i = 0; i < 1000000; i++) {
    sortedArray[i] = i;
  }

  binsearch(55000, sortedArray, 1000000);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC;
  printf("binsearch() took %f seconds to execute \n", time_taken);

  clock_t t2;
  t2 = clock();
  betterbinsearch(55000, sortedArray, 1000000);
  t2 = clock() - t2;
  double time_taken2 = ((double)t2)/CLOCKS_PER_SEC;
  printf("betterbinsearch() took %f seconds to execute \n", time_taken2);

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
