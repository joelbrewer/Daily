#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"

int day1part1();
void day1part2();

int main()
{
  // printf("Day 1 Part 1 : %d\n", day1part1());
  day1part2();
  printf("Day 1 Part 2 : %d\n", day1part1());
}

int day1part1()
{
  printf("day1part1()\n");
  char const* const fileName = "output";
  FILE* file = fopen(fileName, "r");
  char line[512];

  int numGreater = 0;
  int iterator = 0;
  int current = 0, previous = 0;
  printf("Before while\n");
  while (fgets(line, sizeof(line), file)) {
    printf("Inside while\n");
    sscanf(line, "%d", &current);
    if ( (iterator > 0) && (current > previous)) {
      numGreater++;
    }
    previous = current;
    iterator++;
  }

  fclose(file);
  printf("Num greater %d\n", numGreater);
  return numGreater;
}

void day1part2()
{
  printf("day1part2()\n");
  char const* const fileName = "input1.txt";
  char const* const outFileName = "output";
  FILE* file = fopen(fileName, "r");
  FILE* fileOut = fopen(outFileName, "w");

  char line[256];
  
  int g1 = 0; 
  int g2 = 0; 
  int g3 = 0; 

  int iterator = 1;
  int current = 0;

  while (fgets(line, sizeof(line), file)) {
    sscanf(line, "%d", &current);

    if (iterator == 1) {
      g1 += current;
    }

    if (iterator == 2) {
      g1 += current;
      g2 += current;
    }

    if (iterator == 3) {
      g1 += current;
      g2 += current;
      g3 += current;
    }

    if (iterator == 4) {
      fprintf(fileOut, "%d\n", g1);
      g1 = 0;
      g1 += current;
      g2 += current;
      g3 += current;
    }

    if (iterator == 5) {
      fprintf(fileOut, "%d\n", g2);
      g2 = 0;
      g1 += current;
      g2 += current;
      g3 += current;
    }

    if (iterator == 6) {
      fprintf(fileOut, "%d\n", g3);
      g3 = 0;
      g1 += current;
      g2 += current;
      g3 += current;
      iterator = 3;
    }

    iterator++;
  }

  if (iterator == 4) {
    fprintf(fileOut, "%d\n", g1);
  }

  if (iterator == 5) {
    fprintf(fileOut, "%d\n", g2);
  }

  if (iterator == 6) {
    fprintf(fileOut, "%d\n", g3);
  }

  fclose(file);
  fclose(fileOut);
}
