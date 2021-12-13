#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"
#define MAXALIGN 16

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

void parsePositions()
{
  char const* const fileName = "test7.txt";
  char input[5000];
  const char delimiters[] = ",";
  FILE* file = fopen(fileName, "r");
  char *num;
  fscanf(file, "%[^\n]", input);
  num = strtok(input,delimiters);
  while(num != NULL) {
    insertFirst(atoi(num));
    num = strtok(NULL, delimiters);
  }
}

void calculateFuel()
{
}

void part1()
{
}

void part2()
{
}

int main()
{
  part1();
  part2();
}
