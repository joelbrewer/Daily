#include <stdio.h>
#define TABINC 8
#define MAXCOL 8

/* Note: Copied this solution from K&R answers manual */
void fold();

int main()
{
  fold();
}

void fold()
{
  int c, pos;
  for (pos = 1; (c = getchar()) != EOF; ++pos) {
    if (pos > MAXCOL) {
      putchar('\n');
      putchar(c);
      pos = 1;
    } else {
      putchar(c);
    }
  }
}

void detab()
{
  int c, nb, nt, pos;

  nb = 0;
  nt = 0;
  for (pos = 1; (c = getchar()) != EOF; ++pos) {
    if (c == ' ') {
      if (pos % TABINC != 0)
        ++nb;
      else {
        nb = 0;
        ++nt;
      }
    } else {
      for ( ; nt > 0; --nt)
        putchar('\t');
      if (c == '\t')
        nb = 0;
      else
        for ( ; nb > 0; --nb)
          putchar(' ');
      putchar(c);
      if ( c == '\n')
        pos = 0;
      else if (c == '\t')
        pos = pos + (TABINC - (pos-1) % TABINC) - 1;
    }
  }
}

