#include <stdio.h>

/* 1.5.1 File Copying */

int simpleCopy()
{
  int c;
  while ((c = getchar()) != EOF)
    purchar(c);
}


int main()
{
  simpleCopy();
}

int verboseCopy()
{
  int c;

  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
}

