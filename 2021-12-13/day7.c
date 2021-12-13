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
  char const* const fileName = "input7.txt";
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

int calculateFuel(int final)
{
  int fuel = 0;
  struct node *ptr = head;
  while(ptr != NULL) {
    fuel = fuel + abs((final - (ptr->data)));
    ptr = ptr->next;
  }
  return fuel;
}

int largest()
{
  int largest = 0;
  struct node *ptr = head;
  while(ptr != NULL) {
    if (ptr->data > largest) {
      largest = ptr->data;
    }
    ptr = ptr->next;
  }
  return largest;

}

void part1()
{
  parsePositions();
  int minFuel = 0;
  for(int i = 0; i < largest(); i++) {
    if (i == 0) {
      minFuel = calculateFuel(0);
    } else {
      int fuel = calculateFuel(i);
      if (fuel < minFuel) {
        minFuel = fuel;
      }
    }
  }
  printf("Min fuel : %d\n", minFuel);
}

void part2()
{
}

int main()
{
  part1();
  part2();
}
