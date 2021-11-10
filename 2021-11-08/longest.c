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
  while ((len = getit(line, MAXLINE)) > 0)
    printf("Len : %d \n", len);
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0) {
    printf("Longest: %s", longest);
    printf("Line length: %d", len);
  }
  return 0;
}

int getit(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
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


