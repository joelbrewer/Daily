#include <stdio.h>
#include <stdlib.h>
#include "../lib/jlib.h"

void day1part1();
void day1part2();

struct node *head = NULL;
struct node *current = NULL;

int main(void)
{
  day1part2();
}

void day1part1()
{
  char const* const fileName = "input1.txt";
  FILE* file = fopen(fileName, "r");
  char line[256];

  long current = 0;
  long largest = 0;
  long sum = 0;

  while (fgets(line, sizeof(line), file)) {
    char *ptr;
    long ret;
    ret = strtol(line, &ptr, 10);
    sscanf(line, "%ld", &current);

    if((int)line[0] == 10){
      if (sum > largest) {
        largest = sum;
      }
      sum = 0;
    } else {
      printf("Adding %ld to %ld\n", ret, current);
      sum += ret;
      printf("New current: %ld\n", current);
    }
  }
  printf("Largest: %ld\n", largest);
}

void day1part2()
{
  char const* const fileName = "input1.txt";
  FILE* file = fopen(fileName, "r");
  char line[256];

  long current = 0;
  long sum = 0;

  while (fgets(line, sizeof(line), file)) {
    char *ptr;
    long ret;
    ret = strtol(line, &ptr, 10);
    sscanf(line, "%ld", &current);

    if((int)line[0] == 10){
		  printf("inserting...\n");
			printf("pointer : %p\n", &head);
			insertFirst(sum, &head);
      sum = 0;
    } else {
      sum += ret;
    }
  }
	insertFirst(sum, &head);
  printList(&head);
  sort(&head);
	reverseList(&head);
	printList(&head);
	int total = 0;
	total += deleteFirst(&head)->data;
	total += deleteFirst(&head)->data;
	total += deleteFirst(&head)->data;
  printf("Total : %d\n", total);
}
