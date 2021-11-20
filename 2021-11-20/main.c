#include <stdio.h>
#include <limits.h>
#define TABINC 8
#define MAXCOL 8
#define MAXWORD 100
#define IN 1
#define OUT 0
#define DEBUG 0

void fold();
void ranges();


int main()
{
  ranges();
}

/**
input: hello my name is Joel and I am from Saint Louis
output:
hello my
name is
Joel and
I am
from
Saint
Louis
**/
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

void ranges()
{
  char c;
  printf("\tLow(s)\t\t\tHigh(s)\t\t\tLow(u)\t\tHigh(u)\n");
  printf("char\t%d\t\t\t%d\t\t\t%d\t\t%d\n",SCHAR_MIN, SCHAR_MAX, 0, UCHAR_MAX);
  printf("short\t%d\t\t\t%d\t\t\t%d\t\t%d\n",SHRT_MIN, SHRT_MAX, 0, USHRT_MAX);
  printf("int\t%d\t\t%d\t\t%d\t\t%u\n",INT_MIN, INT_MAX, 0, UINT_MAX);
  printf("long\t%ld\t%ld\t%d\t\t%lu\n",LONG_MIN, LONG_MAX, 0, ULONG_MAX);
  printf("\n");

  c = 128;
  printf("char %c", c);
}

/**
 Chapter 2: Types, Operators, and Expressions
 2.1 - Variable Names
 2.2 - Data Types and Sizes
 2.3 - Constants
 2.4 - Declarations
 2.5 - Artithmetic Operators
 2.6 - Relational and Logical Operators
 2.7 - Type Conversions
 2.8 - Increment and Decrement Operators
 2.9 - Bitwise Operators
 2.10 - Assignment Operators and Expressions
 2.11 - Conditional Expressions
 2.12 - Precedence and Order of Evaluation
**/

