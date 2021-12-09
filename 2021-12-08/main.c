#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"
#define CARDSIZE 5

typedef struct {
	int value;
	int status;
} space;

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

struct board {
	space s[5][5];
};

void insertFirst(int data)
{
  struct node *link = (struct node*) malloc(sizeof(struct node));

  link->data = data;
  link->next = head;
  head = link;
}

void parseNums()
{
  char const* const fileName = "test4.txt";
  char input[1000];
  const char s[2] = ",";
  char *num;
  FILE* file = fopen(fileName, "r");
  fscanf(file, "%[^\n]", input);
  num = strtok(input,s);

  while(num != NULL) {
    printf("%s\n", num);
    num =strtok(NULL, s);
  }

  printf("Input: %s\n", input);
}

int checkForBingo(struct board b)
{
	// check horizontals
	for (int row = 0; row < CARDSIZE; row++) {
		int inRow = 0;
    for (int col = 0; col < CARDSIZE; col++) {
			if (b.s[row][col].status == 1) {
				inRow++;
      }
			if (inRow == 5) {
				return 1;
			}
		}
  }
	// check verticals
	for (int col = 0; col < CARDSIZE; col++) {
		int inRow = 0;
    for (int row = 0; row < CARDSIZE; row++) {
			if (b.s[row][col].status == 1) {
				inRow++;
      }
			if (inRow == 5) {
				return 1;
			}
		}
  }

  // check diagonals
  int inRow = 0;
  for (int i = 0; i < CARDSIZE; i++) {
    if (b.s[i][i].status == 1) {
      inRow++;
    }
    if (inRow == 5) {
      return 1;
    }
  }

  inRow = 0;
  for (int i = 0; i < CARDSIZE; i++) {
    if (b.s[CARDSIZE-i][i].status == 1) {
      inRow++;
    }
    if (inRow == 5) {
      return 1;
    }
  }
	return 0;
}

// Parse nums
// Parse boards
// Add num to boards
// Check all boards for bingo after num >= 5
// Repeat


int main()
{
  parseNums();
	struct board b;
	b.s[0][0] = (space) { .value = 22, .status = 1 };
	b.s[0][1] = (space) { .value = 13, .status = 1 };
	b.s[0][2] = (space) { .value = 17, .status = 1 };
	b.s[0][3] = (space) { .value = 11, .status = 1 };
	b.s[0][4] = (space) { .value = 0,  .status = 0 };

	b.s[1][0] = (space) { .value = 8,  .status = 0 };
	b.s[1][1] = (space) { .value = 2,  .status = 1 };
	b.s[1][2] = (space) { .value = 23, .status = 0 };
	b.s[1][3] = (space) { .value = 4,  .status = 0 };
	b.s[1][4] = (space) { .value = 24, .status = 0 };

	b.s[2][0] = (space) { .value = 21, .status = 1 };
	b.s[2][1] = (space) { .value = 9,  .status = 0 };
	b.s[2][2] = (space) { .value = 14, .status = 1 };
	b.s[2][3] = (space) { .value = 16, .status = 0 };
	b.s[2][4] = (space) { .value = 7,  .status = 0 };

	b.s[3][0] = (space) { .value = 6,  .status = 1 };
	b.s[3][1] = (space) { .value = 10, .status = 0 };
	b.s[3][2] = (space) { .value = 3,  .status = 0 };
	b.s[3][3] = (space) { .value = 18, .status = 1 };
	b.s[3][4] = (space) { .value = 5,  .status = 0 };

	b.s[4][0] = (space) { .value = 1,  .status = 1 };
	b.s[4][1] = (space) { .value = 12, .status = 0 };
	b.s[4][2] = (space) { .value = 20, .status = 0 };
	b.s[4][3] = (space) { .value = 15, .status = 0 };
	b.s[4][4] = (space) { .value = 19, .status = 1 };
	int result = checkForBingo(b);
	printf("Result : %d\n", result);
}
