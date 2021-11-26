#include "jlib.h"
#include <math.h>

int isPrime(long n)
{
  if (n <= 3){
    return n > 1;
  }
  if (n%2 == 0 || n % 3 == 0) {
    return 0;
  }
  int i = 5;
  while(pow(i, 2) <= n) {
    if (n % i == 0 || n % (i+2) == 0) {
      return 0;
    }
    i += 6;
  }
  return 1;
}

long smallestPrimeFactor(long n)
{
  for(long i = 2; i < n; i++) {
    if (isPrime(i) == 1 && (n%i == 0) ) {
      return i;
    }
  }
  return n;
}
