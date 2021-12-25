#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"
#define COLMAX 100
#define ROWMAX 100

int finalResult = 0;
int count = 0;
char input[ROWMAX][COLMAX];

void parseInput()
{
  char const* const fileName = "input9.txt";
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
  int isLow = 1;
  int current = input[row][col];

  // check above
  if (row != 0) {
    if (input[row-1][col] < current) {
      isLow = 0;
    }
  }

  // check right
  if (col != COLMAX-1) {
    if (input[row][col+1] <= current) {
      isLow = 0;
    }
  }

  // check below
  if (row != ROWMAX-1) {
    if (input[row+1][col] <= current) {
      isLow = 0;
    }
  }

  // check left
  if (col != 0) {
    if (input[row][col-1] <= current) {
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
        finalResult += (input[row][col] - '0' + 1);
        count++;
      }
    }
  }
  printf("Count: %i\n", count);
  printf("Final Result: %i\n", finalResult);
}

void part2()
{
  // How to tell if a location is in a basin?
  //  - Pretty sure a breadth first search (BFS) of the 2d array is the key
  //      - https://algorithms.tutorialhorizon.com/breadth-first-search-bfs-in-2d-matrix-2d-array/
  //  - First get a map of the locations of all low points (linked-list?)
  //  - Check if there is an un-broken, decreasing trail to a low point (recursive function?)
}

int main()
{
  part1();
}
