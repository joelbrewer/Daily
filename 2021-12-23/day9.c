#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"
#define COLMAX 10
#define ROWMAX 5

int finalResult = 0;
int count = 0;
char input[ROWMAX][COLMAX];

void parseInput()
{
  char const* const fileName = "test9.txt";
  FILE* file = fopen(fileName, "r");
  char line[256];
	int rowIndex = 0;
  while (fgets(line, sizeof(line), file)) {
		for(int i = 0; i < COLMAX; i++) {
      input[rowIndex][i] = line[i];
		}
		rowIndex++;
	}
  fclose(file);
}

int isLowPoint(int row, int col) {
  int isLow = 0;
  int current = input[row][col];
  // check above
  if (row != 0) {
    if (input[row-1][col] > current) {
      printf("Input[%i][%i] : ", row, col);
      printf("Above is higher\n");
      isLow = 0;
    }
  }

  // check right
  if (col != COLMAX-1) {
    if (input[row][col+1] >= current) {
      printf("Input[%i][%i] : ", row, col);
      printf("Right is higher\n");
      isLow = 0;
    }
  }

  // check below
  if (row != ROWMAX-1) {
    if (input[row+1][col] >= current) {
      printf("Input[%i][%i] : ", row, col);
      printf("Below is higher\n");
      isLow = 0;
    }
  }

  // check left
  if (col != 0) {
    if (input[row][col-1] >= current) {
      printf("Input[%i][%i] : ", row, col);
      printf("Left is higher\n");
      isLow = 0;
    }
  }

  return isLow;
}

void part1()
{
  parseInput();
  for(int row = 0; row < ROWMAX; row++) {
    for(int col = 0; col < COLMAX; col++) {
      if (isLowPoint(row,col) == 1) {
        printf("low point : input[%i][%i]\n", row, col);
        count++;
      }
      printf("Count: %i\n", count);
    }
  }
}


int main()
{
  part1();
}
