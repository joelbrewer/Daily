#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"

int any(char s1[], char s2[]);

int main()
{
  char s1[] = "Who's there? Nay, answer me: stand, and unfold yourself.";
  char s2[] = "aeiou";
  int output;
  printf("Input : %s\n", s1);
  output = any(s1,s2);
  printf("Output : %d\n", output);
  return 0;
}

// Returns the first location in the string s1 where any character from
// the string s2 occurs, or -1 if s1 contains no chars from s2
// Example input:
// s1 = "Who's there? Nay, answer me: stand, and unfold yourself."
// s2 = "aeiou"
//
// Example output:
// 2
int any(char s1[], char s2[])
{
  char c, c2;
  int i = 0; // Length of s2
  int j = 0; // Current index of s1
  int matchedIndex = -1; // Index of first matching char

  while ((c = s2[i]) != '\0') {
    i++;
  }

  while ((c2 = s1[j]) != '\0') {
    for (int k = 0; k < i; k++) {
      if (c2 == s2[k]) {
        matchedIndex = j;
        break;
      }
    }
    if (matchedIndex != -1) {
      break;
    }
    j++;
  }
  return matchedIndex;
}
