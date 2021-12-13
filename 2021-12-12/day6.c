#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"
#define GENERATIONSPART1 80
#define GENERATIONSPART2 256

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

long fish[9] = {0};

void parseInitialState()
{
  char const* const fileName = "input6.txt";
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

void parseInitialState2()
{
  char const* const fileName = "input6.txt";
  char input[5000];
  const char delimiters[] = ",";
  FILE* file = fopen(fileName, "r");
  char *num;
  fscanf(file, "%[^\n]", input);
  num = strtok(input,delimiters);
  while(num != NULL) {
    fish[atoi(num)]++;
    num = strtok(NULL, delimiters);
  }
}

void printList()
{
  struct node *ptr = head;
  printf("\n[ ");

  while(ptr != NULL) {
    printf("%d", ptr->data);
    ptr = ptr->next;
  }

  printf(" ]");
}

void breed()
{
  struct node *ptr = head;
  for(int i = 0; i < GENERATIONSPART1; i++) {
    while(ptr != NULL) {
      if (ptr->data == 0) {
        ptr->data = 6;
        insertFirst(8);
      } else {
        ptr->data--;
      }
      ptr = ptr->next;
    }
    ptr = head;
  }
}

void breed2()
{
  long tmp[9] = { 0 };
  for(int i = 0; i < GENERATIONSPART2; i++) {
    for(int j = 0; j < 9; j++) {
      tmp[j] = fish[j];
    }

    fish[0] = tmp[1];
    fish[1] = tmp[2];
    fish[2] = tmp[3];
    fish[3] = tmp[4];
    fish[4] = tmp[5];
    fish[5] = tmp[6];
    fish[6] = tmp[7] + tmp[0];
    fish[7] = tmp[8];
    fish[8] = tmp[0];
  }
}

int countFish()
{
  int numFish = 0;
  struct node *ptr = head;
  while(ptr != NULL) {
    numFish++;
    ptr = ptr->next;
  }
  return numFish;
}

long countFish2()
{
  long numFish = 0;
  for(int i = 0; i < 9; i++) {
    numFish += fish[i];
  }
  return numFish;
}

void part1()
{
  parseInitialState();
  breed();
  printf("Part 1 : %d\n", countFish());
}

void part2()
{
  parseInitialState2();
  breed2();
  printf("Part 2 : %ld\n", countFish2());
}


int main()
{
  part1();
  part2();
}
