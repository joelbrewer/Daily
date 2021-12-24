#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"

int finalResult = 0;

void parseInput()
{
  char const* const fileName = "test9.txt";
  FILE* file = fopen(fileName, "r");
  char line[256];
  while (fgets(line, sizeof(line), file)) {
	}
  fclose(file);
}

void part1()
{
parseInput();
printf("Final result: %i", finalResult);
}

int main()
{
  part1();
}
