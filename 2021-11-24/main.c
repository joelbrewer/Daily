#include <stdio.h>

int atoi(char s[]);
int fib(int i);
int sumFib();

int main()
{
  printf("sumFib() : %d\n", sumFib());
  return 0;
}

int atoi(char s[])
{
  int i, n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
    printf("s[i] %d\n", s[i]);
    printf("'0' %d\n", '0');
    printf("s[i] - '0' : %d\n", s[i] - '0');
    n = 10 * n + (s[i] - '0');
  }
  return n;
}

int sumFib()
{
  int f;
  int sum = 0;
  int i = 1;

  while(1) {
    f = fib(i);
    printf("f : %d\n", f);
    if (f >= 4000000) {
      break;
    }
    if(f%2 == 0) {
      sum = sum + f;
    }
    i++;
  }
  return sum;
}

int fib(int n)
{
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else {
    return fib(n-2) + fib(n-1);
  }
}

