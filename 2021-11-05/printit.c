#include <stdio.h>

#define   IN    1
#define   OUT   0

int main()
{
  printf("Printing those words one at a time.");
  printf("\n");
  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      printf("\n");
    }
    printf("%c", c);
  }
  printf("%c", c);
  return 0;
}
