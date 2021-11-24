#include <stdio.h>
#define MAXLINE 1000

int main()
{
  int i, c;
  char s[MAXLINE];
  int lim = MAXLINE;
  for(i = 0; i < lim-1; i++) {
    c = getchar();
    if (c == '\n')
      break;
    if (c == EOF)
      break;
    s[i] = c;
  }
  return 0;
}
