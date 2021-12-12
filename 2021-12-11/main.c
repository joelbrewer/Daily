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

struct board boards[100];

void insertFirst(int data)
{
  struct node *link = (struct node*) malloc(sizeof(struct node));

  link->data = data;
  link->next = head;
  head = link;
}

int numBoards = 0;
char *num;

void printBoard(struct board b)
{
  for (int i = 0; i < CARDSIZE; i++) {
    for (int j = 0; j < CARDSIZE; j++) {
      if ((j%5) == 0) {
        printf("\n");
      }
      printf("%d(%d) ", b.s[i][j].value, b.s[i][j].status);
    }
  }
}

int getAnswer(struct board b, int num)
{
  int sum = 0;
  for (int i = 0; i < CARDSIZE; i++) {
    for (int j = 0; j < CARDSIZE; j++) {
      if (b.s[i][j].status == 0) {
        sum += b.s[i][j].value;
      }
    }
  }
  return sum*num;
}

void addNum(int num)
{
  // It would probably be cleaner to store 
  // boards in a linked list. This would
  // also allow for n boards, versus the
  // hard limit imposed by an array.
  for (int i = 0; i < numBoards; i++) {
    for (int j = 0; j < CARDSIZE; j++) {
      for (int k = 0; k < CARDSIZE; k++) {
        if (boards[i].s[j][k].value == num) {
          boards[i].s[j][k].status = 1;
        }
      }
    }
  }
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

int checkforBingos(int num)
{
  for(int i = 0; i < numBoards; i++) {
    if (checkForBingo(boards[i]) == 1) {
      // printf("Winner: board %d\n", i);
      // return i;
      struct node *ptr = head;
      int alreadyWon = 0;
      while(ptr != NULL) {
        if (ptr->data == i) {
          alreadyWon = 1;
        }
        ptr = ptr->next;
      }
      if (alreadyWon == 0) {
        insertFirst(i);
      }
    }
  }
  return -1;
}

void parseNums()
{
  char const* const fileName = "input4.txt";
  char input[2000];
  const char s[2] = ",";
  FILE* file = fopen(fileName, "r");
  fscanf(file, "%[^\n]", input);
  num = strtok(input,s);

  while(num != NULL) {
    printf("%s\n", num);
    addNum(atoi(num));
    int b = checkforBingos(atoi(num));
    if (b != -1) {
      printf("We have a winner! (Num: %d, Board: %d)\n", atoi(num), b);

      printBoard(boards[b]);
      int a = getAnswer(boards[b], atoi(num));
      printf("Answer : %d\n", a);
    }
    num =strtok(NULL, s);
  }

  fclose(file);
  printf("Input: %s\n", input);
}

void parseBoards()
{
  printf("parseBoards()\n");
  char const* const fileName = "input4.txt";
  const char s[2] = " ";
  FILE* file = fopen(fileName, "r");
  char line[256];
  int count = 0;
  char *num;
  int currentBoardIndex = -1;

  while (fgets(line, sizeof(line), file)) {
    // printf("inside loop\n");
    num = strtok(line, " ");
    int currentRow = ((count-2)%6)-1;
    // printf("currentRow %d\n", currentRow);
    // printf("count %d\n", count);

    if ((count+3) % 6 == 0 ) {
      currentBoardIndex++;
      numBoards++;
    }

    if (count > 2 && (currentRow != -1) && (*num != 10)) {
       // printf("count > 2\n");
      int currentCol = 0;
      while(num != NULL) {
        // printf("inside while\n");
        printf("currentBoardIndex : %d\n", currentBoardIndex);
        printf("count : %d\n", count);
        printf("currentRow : %d\n", currentRow);
        printf("currentCol : %d\n", currentCol);
        printf("num : %d\n", *num);
        printf("num : %s\n", num);
        printf("num : %d\n", atoi(num));
        boards[currentBoardIndex].s[currentRow][currentCol] = (space) { .value = atoi(num), .status = 0 };
        currentCol++;
        num = strtok(NULL, s);
      }
    }

    count++;
  }
  fclose(file);
}

int main()
{
  parseBoards();
  printBoard(boards[0]);
  parseNums();

	// int result = checkForBingo(b);
	// printf("Result : %d\n", result);
}
