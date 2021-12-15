#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"
#define ONELENGTH 2
#define FOURLENGTH 4
#define SEVENLENGTH 3
#define EIGHTLENGTH 7


struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;
void insertFirst(int data)
{
  struct node *link = (struct node*) malloc(sizeof(struct node));
  link->data = data;
  link->next = head;
  head = link;
}

int ones = 0;
int fours = 0;
int sevens = 0;
int eights = 0;


void parseInput()
{
  char const* const fileName = "input8.txt";
  const char delimiters[] = "|";
  FILE* file = fopen(fileName, "r");
  char line[256];
  char *firstPart;
  char *secondPart;
  while (fgets(line, sizeof(line), file)) {
    strtok(line, "\n");
		firstPart = strtok(line,delimiters);
		secondPart = strtok(NULL, delimiters);

    char *word;

    word = strtok(secondPart, " ");
    while(word != NULL) {
      switch(strlen(word)) {
        case ONELENGTH :
          ones++;
          break;
        case FOURLENGTH :
          fours++;
          break;
        case SEVENLENGTH :
          sevens++;
          break;
        case EIGHTLENGTH :
          eights++;
          break;
        default :
          break;
        ;
      }
      word = strtok(NULL, " ");
    }
	}
}

int total()
{
  return ones + fours + sevens + eights;
}

void part1()
{
  parseInput();
  printf("Part 1 : %d\n", total());
}

// First, we know what 1, 4, 7 and 8 are.
// Is there an order we should logically follow?
// What data structures work best for this problem?
// What methods need to be written?
// I could try and solve one manually, then reverse-engineer my manual process?
//
// Length   Options
// ================
// 2        1
// 3        7
// 4        4
// 5        2,3,5
// 6        0,6,9
// 7        8

void part2()
{
}

int main()
{
  part1();
  // part2();
}
