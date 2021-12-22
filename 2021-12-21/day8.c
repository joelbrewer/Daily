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

void permute(char *a, int l, int r, char *p);

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
  fclose(file);
}

void parseInputPart2()
{
  char const* const fileName = "test8-2.txt";
  const char delimiters[] = "|";
  FILE* file = fopen(fileName, "r");
  char line[256];
  char *firstPart;
  char *secondPart;
  while (fgets(line, sizeof(line), file)) {
    strtok(line, "\n");
		firstPart = strtok(line,delimiters);
		secondPart = strtok(NULL, delimiters);

    // char *word;

		char str[] = "abcdefg";
		int n = strlen(str);
		// printf("firstPart %s\n", firstPart);
		// int nums[10];
		permute(str, 0, n-1, firstPart);

	}
  fclose(file);
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
//
// 5        2,3,5
// 6        0,6,9
//
// 7        8

// Solve more like a logic puzzle?
// For each remaining string, check against every possibility?
//
//
// if length == 5
//
//    try against known
// if length == 6
//    try against known

void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int makesNum(char *w, char *a)
{
	printf("makesNum() : %s : %s \n", w, a);
	char numZero[] = "1110111";
	char numOne[] = "0010010";
	char numTwo[] = "1011101";
	char numThree[] = "1011011";
	char numFour[] = "0111010";
	char numFive[] = "1101011";
	char numSix[] = "1101111";
	char numSeven[] = "1010010";
	char numEight[] = "1111111";
	char numNine[] = "1111011";

	char on[] = "0000000";
	for(int i = 0; i<10; i++) {
		if(strchr(w, a[0])) {
			on[i] = 1;
		}
	}

	if (strcmp(on, numZero) == 0) {
		return 0;
	} else if (strcmp(on, numOne) == 0) {
		return 1;
	} else if (strcmp(on, numTwo) == 0) {
		return 2;
	} else if (strcmp(on, numThree) == 0) {
		return 3;
	} else if (strcmp(on, numFour) == 0) {
		return 4;
	} else if (strcmp(on, numFive) == 0) {
		return 5;
	} else if (strcmp(on, numSix) == 0) {
		return 6;
	} else if (strcmp(on, numSeven) == 0) {
		return 7;
	} else if (strcmp(on, numEight) == 0) {
		return 8;
	} else if (strcmp(on, numNine) == 0) {
		return 9;
	} else {
		return -1;
	}
}

/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string.
4. Word patterns */
void permute(char *a, int l, int r, char *p)
{
	char part1[60];
	char *word;
	int nums[10];
	int n;
	copy(part1, p);

 	int i;
 	if (l == r) {
		memset(nums, 0, sizeof(nums));
    word = strtok(part1, " ");
 		// loop through each word
     while(word != NULL) {
			 int num = makesNum(word, a);
			 if( (num != -1) && (nums[num-1] == 0) ) {
				 nums[num-1] = 1;
			 } else {
				break;
			}
			 word = strtok(NULL, " ");
		 }
			
		 n = 0;
		 for (int i = 0; i < 10; i++) {
		   if(nums[i] == 1) {
					n++;
				} else {
					break;
				}
		}

		if (n == 9) {
			printf("We have a solution!\n");
			printf("Permutation: %s\n", a);
			return;
		}
		
 		word = NULL;
 	} else {
 		for (i = l; i <= r; i++) {
 				swap((a+l), (a+i));
 				permute(a, l+1, r, part1);
 				swap((a+l), (a+i)); //backtrack
 		}
 	}
}

void part2()
{
parseInputPart2();
}

int main()
{
  // part1();
  part2();
}
