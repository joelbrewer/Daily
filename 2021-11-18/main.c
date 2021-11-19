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

// hello my name is
// Joel and I am
//
// hello my
// name is Joel
// and I am
// from Saint
// Louis

int main()
{
  fold();
}

void fold()
{
  char word[MAXWORD]; // current word
  int c, col, wordLength, wordStart, state;
  wordLength = 0;
  wordStart = 0;
  state = OUT;

  for (col = 1; (c = getchar()) != EOF; ++col) {

    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      // Print the previous word
      //
      // printf("printing previous\n");
      // printf("wordStart %d\n", wordStart);
      // printf("wordLength %d\n", wordLength);

      // printf("\nbeforePrint\n");
      // printf("wordStart : %d\n", wordStart);
      if ((wordStart - 1 + wordLength) <= MAXCOL) {
        for(int i = 0; i < wordLength; i++) {
          putchar(word[i]);
          col++;
        }
        putchar(' ');
      } else {
        putchar('\n');
        col = 1;

        // This won't account for words that are greater than MAXCOL
        // Will need to add handling to wrap those
        for(int i = 0; i < wordLength; i++) {
          putchar(word[i]);
          col++;
        }
        putchar(' ');
      }
      wordStart = col;
      // Now we've hit an actual char
    } else if (state == OUT) {
      wordStart = col;
      state = IN;
      wordLength = 0;
      wordLength++; // this wil be 1
      word[0] = c;
      word[1] = '\0';
    } else {
      wordLength++;
      word[wordLength-1] = c;
      word[wordLength] = '\0';
    }
    // printf("c : %c\n", c);
    // printf("col : %d\n", col);
    // printf("wordLength : %d\n", wordLength);
    // printf("wordStart : %d\n", wordStart);
    // printf("state %d\n", state);
    // printf("word %s\n", word);
  }
}

