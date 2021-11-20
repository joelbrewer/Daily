#include <stdio.h>
#define TABINC 8
#define MAXCOL 8
#define MAXWORD 100
#define IN 1
#define OUT 0
#define DEBUG 0

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
  int c, wordLength, wordStart, state, outputPointer;
  wordLength = 0;
  wordStart = 0;
  outputPointer = 1;
  state = OUT;

  while((c = getchar()) != EOF ){
    if (outputPointer > 8) {
      putchar('\n');
      outputPointer = 1;
    }

    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      // Print the previous word
      //
      // printf("printing previous\n");
      // printf("wordStart %d\n", wordStart);
      // printf("wordLength %d\n", wordLength);

      // printf("\nbeforePrint\n");
      // printf("wordStart : %d\n", wordStart);
      if ((outputPointer - 1 + wordLength) <= MAXCOL) {
        for(int i = 0; i < wordLength; i++) {
          putchar(word[i]);
          outputPointer++;
        }
        putchar(' ');
        outputPointer++;
      } else {
        putchar('\n');
        outputPointer = 1;

        // This won't account for words that are greater than MAXCOL
        // Will need to add handling to wrap those
        for(int i = 0; i < wordLength; i++) {
          if (i > 7) {
            putchar('\n');
            outputPointer = 1;
          }
          putchar(word[i]);
          outputPointer++;
        }
        putchar(' ');
        outputPointer++;
      }
      // Now we've hit an actual char
    } else if (state == OUT) {
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
    if (DEBUG) {
      printf("=== c : %c\n", c);
      printf("=== wordLength : %d\n", wordLength);
      printf("=== wordStart : %d\n", wordStart);
      printf("=== state %d\n", state);
      printf("=== word %s\n", word);
      printf("=== outputPointer %d", outputPointer);
      printf("\n");
    }
  }
}

