#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"
#define NUMBITS 5

int day3part1();
int fromBinary(const char * str);

int main()
{
  printf("Day 3 Part 1 : %d\n", day3part1());
}
// create an array of ints to hold the number of on-bits for each position
// eg: [1,2,3,4,5,6,7,8,9,10,11,12]

int day3part1()
{
  int counts[NUMBITS] = {0,0,0,0,0};
  int output[NUMBITS] = {0,0,0,0,0};
  int totalLines = 0;
  char const* const fileName = "test3.txt";
  FILE* file = fopen(fileName, "r");
  char line[512];

  while (fgets(line, sizeof(line), file)) {
    int i = 0;
    int c = 0;
    totalLines++;

    while ((c = line[i]) != '\n') {
      printf("c : %d\n", c - '0');
      counts[i] += c - '0';
      i++;
    }
  }
  printf("Total lines : %d\n", totalLines);
  for (int i = 0; i < NUMBITS; i++) {
    if (counts[i] > totalLines/2) {
      output[i] = 1;
    }
    //printf("counts[%d] : %d\n", i, counts[i]);
    printf("output[%d] : %d\n", i, output[i]);
  }
  printf("output as decimal %d\n", fromBinary(output));
  return 0;
}

int fromBinary(const char *s) {
  return (int) strtol(s, NULL, 2);
}
