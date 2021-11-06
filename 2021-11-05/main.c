#include <stdio.h>

int putChar()
{
  int c;
  c = getchar() != EOF;
  printf("Value: %d", c);
  printf("Value of EOF: %d", EOF);
  return 0;
}

int countChar()
{
  long nc;

  nc = 0;
  while (getchar() != EOF)
    ++nc;
  printf("%ld\n", nc);
  return 0;
}

void countCharV2()
{
  double nc;

  for (nc = 0; getchar() != EOF; ++nc)
    ;
  printf("%.0f\n", nc);
}

void countLines()
{
  int c, nl;
  nl = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n')
      ++nl;
  printf("%d\n", nl);
}

void countBlanks()
{
  int c, b;
  b = 0;
  while ((c = getchar()) !=EOF)
    if (c == ' ' || c == '\n' || c == '\t')
      ++b;
  printf("%d\n", b);
}

void replaceBlanks()
{
  char c, l = 0;
  while((c = getchar()) != EOF) {
    if (c == ' ' && l == ' ');
    else
      printf("%c", c);
    l = c;
  }
}

void replaceSpecials()
{
  char c = 0;
  while((c = getchar()) != EOF) {
    if (c == '\t')
      printf("\\t");
    else if (c == '\b')
      printf("\\b");
    else if (c == '\\')
      printf("\\");
    else
      printf("%c", c);
  }
}

int main()
{
  replaceSpecials();
}
