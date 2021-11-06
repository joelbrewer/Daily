#include <stdio.h>

#define   IN    1
#define   OUT   0

int main()
{
  printf("Counting lines, words, and chars");
  printf("\n");
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("\n");
  printf("Lines: %d\n", nl);
  printf("Words: %d\n", nw);
  printf("Chars: %d\n", nc);
  return 0;
}
