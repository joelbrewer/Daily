#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"
#define NUMBITS 5

int day3part2();

int main()
{
  printf("Day 3 Part 2 : %d\n", day3part2());
}

int day3part2()
{
  int counts[NUMBITS] = {0,0,0,0,0};
  char output[NUMBITS] = {'0','0','0','0','0'};

  int input[1000][NUMBITS] = {{0}};

  int currentLine = 0;
  char const* const fileName = "test3.txt";
  FILE* file = fopen(fileName, "r");
  char line[512];

  int ox = 0;
  int co = 0;

  while (fgets(line, sizeof(line), file)) {

    int i = 0;
    int c = 0;

    while ((c = line[i]) != '\n') {
      input[currentLine][i] = c - '0';
      i++;
    }
    currentLine++;
  }

  input[5][0] = NULL;
  printf("input[5][0] : %d\n", input[5][0]);
  printf("input[5][1] : %d\n", input[5][1]);
  printf("input[5][2] : %d\n", input[5][2]);
  printf("input[5][3] : %d\n", input[5][3]);
  printf("input[5][4] : %d\n", input[5][4]);

  // for (int i = 0; i < NUMBITS; i++) {
  //   if (counts[i] > totalLines/2) {
  //     output[i] = '1';
  //   }
  // }

	// for (int i = 0; i < NUMBITS ; i++) {
	// 	if (output[NUMBITS-i-1] - '0' == 1) {
	// 		gamma += pow(2,i);
	// 	} else {
	// 		epsilon += pow(2,i);
	// 	}
	// }
  // return gamma*epsilon;
}
