#include <stdio.h>
#define TABSTOP 8
#define MAXLINE 1000
#define MAXBUFFER 10000

// Entab should:
// - Replaces strings of blanks by the minimum number of tabs and blanks
//   to achieve the same spacing.

int nextTabStop(int column);
int spacesToAdd(int column);
int getit(char s[], int lim);
void convertToTabsAndSpaces(char s[], char o[]);
void copyToOutput(char to[], char from[]);
void insertTabsAndSpaces(int i, int j, char s[]);

int outputIndex = 0;

int main()
{
  char line[MAXLINE]; // current input line
  char lineEntabbed[MAXLINE]; // current output line
  char output[MAXBUFFER] = { 0 }; 
  int len; // current line length
  while ((len = getit(line, MAXLINE)) > 0) {
    convertToTabsAndSpaces(line, lineEntabbed);
    copyToOutput(output, lineEntabbed);
  }

  printf("Output:\n");
  printf("%s\n", output);

  return 0;
}

void convertToTabsAndSpaces(char s[], char o[])
{
  printf("convertToTabsAndSpaces\n");
  int c, i, j;
  i = 0;
  j = 0;
  while((c = s[i]) != '\0') {
    if (i < (MAXLINE-1) && c != ' ') {
      o[i] = c;
      i++;
    }
    if (c == ' ') {
      j++;
      i++;
      while(s[i] == ' ') {
        j++;
        i++;
      }
      printf("i : %d\n", i);
      printf("j : %d\n", j);
      insertTabsAndSpaces(i,j,o);
      j = 0;
    }
  }
  if (c == '\n') {
    if (i < (MAXLINE-1)) {
      o[i] = c;
    }
  }
  o[i] = '\0';
}

void insertTabsAndSpaces(int i, int j, char s[])
{
  printf("insertTabsAndSpaces\n");
  if (j + i > nextTabStop(i)) {
    s[i] = '\t';
    j = j - (nextTabStop(i) - i);
    i = nextTabStop(i);
    insertTabsAndSpaces(i, j, s);
  } else {
    for (int k = 0; k < j; k++) {
      s[i+k] = ' ';
    }
  }
}

int getit(char s[], int lim)
{
  int c, i, sp;
  i = 0;

  while ((c = getchar()) != EOF && c != '\n') {
    if (i < (MAXLINE-1) && c != '\t') {
      s[i] = c;
      i++;
    }
    if (c == '\t') {
      sp = spacesToAdd(i);
      for (int j = sp; j > 0; j--) {
        s[i] = ' ';
        i++;
      }
    }
  }
  if (c == '\n') {
    if (i < (MAXLINE-1)) {
      s[i] = c;
    }
  }
  s[i] = '\0';
  return i;
}

int nextTabStop(int column)
{
  return (column + TABSTOP) / TABSTOP * TABSTOP;
}

int spacesToAdd(int column)
{
  return nextTabStop(column) - column;
}

void copyToOutput(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[outputIndex] = from[i]) != '\0') {
    ++outputIndex;
    ++i;
  }
  to[outputIndex] = '\n';
  ++outputIndex;
}

