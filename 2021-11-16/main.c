#include <stdio.h>
#define TABINC 8
#define MAXCOL 8
#define MAXWORD 100
#define IN 1
#define OUT 0

void fold();

// input: hello my name is Joel and I am from Saint Louis
// output:
// hello my
// name is
// Joel and
// I am
// from
// Saint
// Louis

int main()
{
  fold();
}

void fold()
{
  char word[MAXWORD]; // current word
  int c, pos, l, wordStart, state;
  l = 0;
  wordStart = 0;
  state = OUT;

  for (pos = 1; (c = getchar()) != EOF; ++pos) {

    if (c == '\n') {
      pos = 1;
      l = 0;
      wordStart = pos;
    }

    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      if ((wordStart + l - 1) < MAXCOL) {
        for(int i = 0; i < l; i++) {
          putchar(word[i]);
        }
      } else {
        putchar('\n');
        for(int i = 0; i < l; i++) {
          putchar(word[i]);
        }
        pos = 1;
      }
      wordStart = pos;
    } else if (state == OUT) {
      wordStart = pos;
      state = IN;
      l++;
      word[pos-1] = c;
    } else {
      l++;
      word[pos-1] = c;
    }
  }
}

