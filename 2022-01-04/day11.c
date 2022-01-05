#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include "../lib/jlib.h"
#define COLMAX 10
#define ROWMAX 10

int finalResult = 0;
int count = 0;
int input[ROWMAX][COLMAX];

int dRow[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int dCol[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

void parseInput()
{
  char const* const fileName = "input11.txt";
  FILE* file = fopen(fileName, "r");
  char line[256];
	int rowIndex = 0;
  while (fgets(line, sizeof(line), file)) {
		for(int i = 0; i < COLMAX; i++) {
      input[rowIndex][i] = line[i] - '0';
		}
		rowIndex++;
	}
  fclose(file);
}

int checkForSync() {
  for (int i = 0; i < ROWMAX; i++) {
    for (int j = 0; j < COLMAX; j++) {
      if (input[i][j] != 0) {
        return 0;
      }
    }
  }
  return 1;
}

void increaseEnergyLevels()
{
  for (int i = 0; i < ROWMAX; i++) {
    for (int j = 0; j < COLMAX; j++) {
      input[i][j]++;
    }
  }
}

void printInput()
{
  for (int i = 0; i < ROWMAX; i++) {
    for (int j = 0; j < COLMAX; j++) {
      printf("%d", input[i][j]);
      if (j == COLMAX-1)
        printf("\n");
    }
  }
}

int isValid(int flashed[][COLMAX], int row, int col)
{
  if (row < 0 || col < 0 || row >= ROWMAX || col >= COLMAX) {
    return 0;
  };

  return 1;
}

void handleFlash(int flashed[][COLMAX], int row, int col)
{
  flashed[row][col] = 1;
  count++;
  // Increase adjacent cells
  for(int i = 0; i < 8; i++) {
    int adjx = row + dRow[i];
    int adjy = col + dCol[i];
    if (isValid(flashed, adjx, adjy) == 1) {
      input[adjx][adjy]++;
      if (input[adjx][adjy] > 9 && flashed[adjx][adjy] == 0) {
        handleFlash(flashed, adjx, adjy);
      }
    }
  }
}

void handleFlashes()
{
  int flashed[ROWMAX][COLMAX];
  memset(flashed, 0, sizeof(flashed));

  for (int i = 0; i < ROWMAX; i++) {
    for (int j = 0; j < COLMAX; j++) {
      if (input[i][j] > 9 && flashed[i][j] == 0) {
        handleFlash(flashed, i, j);
      }
    }
  }
}

void resetFlashes()
{
  for (int i = 0; i < ROWMAX; i++) {
    for (int j = 0; j < COLMAX; j++) {
      if (input[i][j] > 9) {
        input[i][j] = 0;
      }
    }
  }
}

void step(int n, int sync)
{
  for(int i = 0; i < n; i++) {
    increaseEnergyLevels();
    handleFlashes();
    resetFlashes();
    if (sync == 1 && checkForSync() == 1) {
      printf("Synced! Step %d", i+1);
      return;
    }
  }
}

void part1()
{
  parseInput();
  step(100, 0);
  printf("Num flashes: %d\n", count);

}

void part2()
{
  parseInput();
  step(1000, 1);
}

int main()
{
  part1();
  part2();
}
