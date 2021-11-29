#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"

void squeezeBetter(char s1[], char s2[]);

int main()
{
  char s1[] = "Who's there? Nay, answer me: stand, and unfold yourself.";
  char s2[] = "aeiou";
  printf("Input : %s\n", s1);
  squeezeBetter(s1,s2);
  printf("Output : %s\n", s1);
  return 0;
}

// Deletes each character in s1 that matches any character in s2
// Example input:
// s1 ['a','b','c','d','e','\0']
// s2 ['a','z','\0']
//
// Example output:
// s1 ['b','c','d','e','\0']
//
void squeezeBetter(char s1[], char s2[])
{
  char c, c2;
  int i = 0, j = 0, m = 0;
  while ((c = s2[i]) != '\0') {
    i++;
  }
  while ((c2 = s1[j]) != '\0') {
    int matched = 0;
    for(int k = 0; k < i; k++) {
      if (c2 == s2[k]) {
        matched = 1;
      }
    }
    if (matched == 0) {
      s1[m] = c2;
      m++;
    }
    j++;
  }
  s1[m] = '\0';
}
