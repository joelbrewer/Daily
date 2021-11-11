#include <stdio.h>

#define MAXLINE 1000
#define MAXBUFFER 10000

/* Template File */
// Remove trailing blanks and tabs from each line of input
// Delete entirely blank lines
//
// input:
// aa aaaa    \t
//
// bbbbbb      \t   \t
//
// output:
// aa aaaa
// bbbbbb
//
// getLine
// strip blanks from end of line (work backwards?)
//    - Get length of line
//    - Skipping the \n char, iterate until a char is found
//    - Once a char is found, append \n and \0 to mark end of string, thus "removing" extraneous
//      whitespace chars
// copy line to output

int getStrippedLine(char line[], int maxline);
void copy(char to[], char from[]);

int outputIndex = 0;

int main()
{
  int len, l,  k;
  char line[MAXLINE]; // current input line
  char output[MAXBUFFER] = { 0 }; 
  while ((len = getStrippedLine(line, MAXLINE)) > 0) {
    l = 0;

    // Check for blank line
    while (l < len) {
      k = line[l];
      if (k == '\n' || k == '\t' || k == ' ') {
        l++;
      } else {
        break;
      }
    }
    if (l != len && len > 0) {
      copy(output, line);
    }
  }
  printf("Content: \n%s \n", output);
}

int getStrippedLine(char s[], int lim)
{
  int c, i, j, k;
  i = 0;

  while ((c = getchar()) != EOF && c != '\n') {
    if (i < (lim-1)) {
      s[i] = c;
    }
    i++;
  }

  if (c == '\n') {
    if (i < (lim-1)) {
      s[i] = c;
    }
  }

  j = i;
  // Strip tabs and blank spaces from end of string
  while (j >= 0) {
    k = s[j];
    if (k == '\n' || k == '\t' || k == ' ') {
      j--;
    } else {
      s[j+1] = '\0';
      break;
    }
  }

  return i;
}

void copy(char to[], char from[])
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

