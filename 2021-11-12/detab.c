#include <stdio.h>
#define TABSTOP 8
#define MAXLINE 1000
#define MAXBUFFER 10000

// Detab should:
// - Replace tabs in the input with the proper number of blanks to space to the next tab stop
// - Assume a fixed set of tab stops every n columns

int nextTabStop(int column);
int spacesToAdd(int column);
int getit(char s[], int lim);
void copyToOutput(char to[], char from[]);

int outputIndex = 0;

int main()
{
  char line[MAXLINE]; // current input line
  char output[MAXBUFFER] = { 0 }; 
  int len; // current line length
  while ((len = getit(line, MAXLINE)) > 0) {
    copyToOutput(output, line);
  }

  printf("Output:\n");
  printf("%s\n", output);

  return 0;
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
