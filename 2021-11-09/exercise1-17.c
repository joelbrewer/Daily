#include <stdio.h>
#define MINLINE 80
#define MAXLINE 1000
#define MAXBUFFER 10000

// input:
// aaaaaaaaaa
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
// aaaaaaaaaaaaaaaaaaaa
//
// output:
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

int getit(char line[], int maxline);
void copy(char to[], char from[]);

int outputIndex = 0;

int main()
{
  int len; // current line length
  char line[MAXLINE]; // current input line
  char output[MAXBUFFER]; // lines > 80 stored here

  while ((len = getit(line, MAXLINE)) > 0) {
    printf("Len : %d \n", len);
    if (len > MINLINE) {
      printf("copying... \n");
      copy(output, line);
    }
  }
  printf("Content: \n%s \n", output);
  return 0;
}

int getit(char s[], int lim)
{
  int c, i;
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
  s[i] = '\0';
  return i;
}


void copy(char to[], char from[])
{
  int i;
  i = 0;
  printf("outputIndex before %d \n", outputIndex);
  while ((to[outputIndex] = from[i]) != '\0') {
    ++outputIndex;
    ++i;
  }
  to[outputIndex] = '\n';
  ++outputIndex;
}
