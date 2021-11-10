#include <stdio.h>
#define MAXLINE 5

// - Print the length of arbitrarily long input lines
// - Print as much as possible of the text

int getit(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
  int len; // current line length
  int max; // max length seen thus far
  char line[MAXLINE]; // current input line
  char longest[MAXLINE]; // longest line saved here

  max = 0;
  while ((len = getit(line, MAXLINE)) > 0) {
    printf("Len : %d \n", len);
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) {
    printf("Longest line: %s \n", longest);
    printf("Longest length: %d \n", max);
  }
  return 0;
}

int getit(char s[], int lim)
{
  int c, i;
  i = 0;

  while ((c = getchar()) != EOF && c != '\n') {
    if (i < (MAXLINE-1)) {
      s[i] = c;
    }
    i++;
  }
  if (c == '\n') {
    if (i < (MAXLINE-1)) {
      s[i] = c;
    }
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}



