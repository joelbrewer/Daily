#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUMBITS 12

int day3part1();

int main()
{
  printf("Day 3 Part 1 : %d\n", day3part1());
}

int day3part1()
{
  int counts[NUMBITS];
  char output[NUMBITS];
  int totalLines = 0;
  char const* const fileName = "input3.txt";
  FILE* file = fopen(fileName, "r");
  char line[512];

  int gamma = 0;
  int epsilon = 0;

  while (fgets(line, sizeof(line), file)) {
    int i = 0;
    int c = 0;
    totalLines++;

    // Get counts
    while ((c = line[i]) != '\n') {
      counts[i] += c - '0';
      i++;
    }
  }

  // Calculate most common bits to find gamma rate
  for (int i = 0; i < NUMBITS; i++) {
    if (counts[i] > totalLines/2) {
      output[i] = '1';
    }
  }

  // Calculate gamma and epsilon by loopring through
  // binary gamma rate and converting to decimal
	for (int i = 0; i < NUMBITS ; i++) {
		if (output[NUMBITS-i-1] - '0' == 1) {
			gamma += pow(2,i);
		} else {
			epsilon += pow(2,i);
		}
	}
  return gamma*epsilon;
}
