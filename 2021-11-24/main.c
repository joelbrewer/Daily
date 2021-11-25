#include <stdio.h>

int atoi(char s[]);

int main()
{
  int i;
  char s[] = { '1','2','3','\0' };
  i = atoi(s);
  printf("i : %d", i);
  return 0;
}

int atoi(char s[])
{
  int i, n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}
