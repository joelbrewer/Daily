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

void reverse(char s[])
{
  char out[100];
  int c, i, j;
  i = 0;

  while ((c = s[i]) != '\0')
    i++;

  for (j = 0; j < i; j++) {
    out[j] = s[i-j-1];
  }

  copy(s, out);
}

void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
