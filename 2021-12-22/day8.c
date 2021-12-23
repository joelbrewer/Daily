#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"

int finalResult = 0;

void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int concatenate(int x, int y) {
  int pow = 10;
  while(y >= pow)
    pow *= 10;
  return x * pow + y;        
}

int makesNum(char *w, char *a)
{
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

	for(int i = 0; i<7; i++) {
		if(strchr(w, a[i])) {
			on[i] = '1';
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

void permute(char *a, int l, int r, char *p, char *p2)
{
	char part1[60];
	char part2[60];
	char *word;
	int nums[10];
	int n;
  int result = 0;

	copy(part1, p);
	copy(part2, p2);

 	int i;
 	if (l == r) {
		memset(nums, 0, sizeof(nums));
    word = strtok(part1, " ");
 		// loop through each word
     while(word != NULL) {
			 int num = makesNum(word, a);
			 if( (num != -1) && (nums[num] == 0) ) {
				 nums[num] = 1;
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

		if (n == 10) {

      char *word;

      word = strtok(part2, " ");
      while(word != NULL) {
        int num = makesNum(word, a);
        result = concatenate(result, num);
        word = strtok(NULL, " ");
      }

      finalResult += result;
			return;
		}
		
 		word = NULL;
 	} else {
 		for (i = l; i <= r; i++) {
 				swap((a+l), (a+i));
 				permute(a, l+1, r, part1, part2);
 				swap((a+l), (a+i)); //backtrack
 		}
 	}
}

void parseInputPart2()
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

		char str[] = "abcdefg";
		int n = strlen(str);
		permute(str, 0, n-1, firstPart, secondPart);
	}
  fclose(file);
}


void part2()
{
parseInputPart2();
printf("Final result: %i", finalResult);
}

int main()
{
  part2();
}
