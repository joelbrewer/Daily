#include <stdio.h>
#define MAXLINE 1000
#define MAXBUFFER 10000

/* Input:
 * hello
 * world
 * joel
 * tanya
 *
 * Output:
 * olleh
 * dlrow
 * leoj
 * aynat
 */

void reverse(char s[]);
void copy(char to[], char from[]);
void copyToOutput(char to[], char from[]);
int getit(char s[], int lim);

int outputIndex = 0;

int main()
{
  int len; // current line length
  char line[MAXLINE]; // current input line
  char output[MAXBUFFER] = { 0 }; 
  while ((len = getit(line, MAXLINE)) > 0) {
    reverse(line);
    copyToOutput(output, line);
  }
  printf("Reversed: \n");
  printf("%s\n", output);
  return 0;
}

void reverse(char s[])
{
  char out[100];
  int c, i, j;
  i = 0;

  while ((c = s[i]) != '\0')
    i++;

  for (j = 0; j < i; j++) {
    out[j] = s[i-j-1];
  }

  copy(s, out);
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

