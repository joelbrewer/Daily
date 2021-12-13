#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"
#define MAPSIZE 1000
#define GENERATIONS 256

int map[MAPSIZE][MAPSIZE] = {{0}};

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

void addLine(int coords[4])
{
	int smallY, largeY, smallX, largeX;
	int deltaX, deltaY;
	deltaX = (coords[2] - coords[0]);
	deltaY = (coords[3] - coords[1]);

	if (coords[1] <= coords[3]) {
		smallY = coords[1];
		largeY = coords[3];
	} else {
		smallY = coords[3];
		largeY = coords[1];
	}

	if (coords[0] <= coords[2]) {
		smallX = coords[0];
		largeX = coords[2];
	} else {
		smallX = coords[2];
		largeX = coords[0];
	}

  if (coords[0] == coords[2]) { // Vertical
    for(int i = smallY; i <= largeY; i++) {
      map[coords[0]][i]++;
    }
  } else if (coords[1] == coords[3]) { // Horizontal
    for(int i = smallX; i <= largeX; i++) {
      map[i][coords[1]]++;
    }
  } else { // Diaganol

		int slope = -(deltaY/deltaX);

		if (slope > 0) {
			for(int i = 0; i <= largeX-smallX; i++) {
				map[smallX+i][largeY-i]++;
			}
		} else {
			for(int i = 0; i <= largeX-smallX; i++) {
				map[smallX+i][smallY+i]++;
			}
		}
	}
}

int dangerousAreas()
{
  int sum = 0;
  for(int i = 0; i < MAPSIZE; i++) {
    for(int j = 0; j < MAPSIZE; j++) {
      if (map[i][j] >= 2) {
        sum++;
      }
    }
  }
  return sum;
}

void parseInput()
{
  char const* const fileName = "input5.txt";
  const char delimiters[] = " , -> ";
  FILE* file = fopen(fileName, "r");
  char line[256];
  int coordinates[4] = {0};
  char *token;

  while (fgets(line, sizeof(line), file)) {
    token = strtok(line, delimiters);
    int i = 0;
		while (token != NULL)
		{
      coordinates[i] = atoi(token);
      token = strtok(NULL, delimiters);
      i++;
		}

    addLine(coordinates);
  }
  fclose(file);
}

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
    // printf("Inserting...");
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
    // printf("Inserting...");
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
  for(int i = 0; i < GENERATIONS; i++) {
    printf("Generation: %d\n", i);
    while(ptr != NULL) {
      // printf("Data : %d", ptr->data);
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
  for(int i = 0; i < GENERATIONS; i++) {
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


int main()
{
  // Day 5
  // parseInput();
  // int answer = dangerousAreas();
  // printf("Answer : %d\n", answer);
  
  // Day 6
  parseInitialState2();
  breed2();
  for (int i = 0; i < 9; i++) {
    printf("Fish[%d] : %ld\n", i, fish[i]);
  }
  // printList();
  printf("Answer : %ld\n", countFish2());
}
