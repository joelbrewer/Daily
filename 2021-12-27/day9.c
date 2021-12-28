#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include "../lib/jlib.h"
#define COLMAX 10
#define ROWMAX 5

int finalResult = 0;
int count = 0;
int input[ROWMAX][COLMAX];
int vis[ROWMAX][COLMAX];

int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

struct Pair {
  int first;
  int second;
};

void parseInput()
{
  char const* const fileName = "test9.txt";
  FILE* file = fopen(fileName, "r");
  char line[256];
	int rowIndex = 0;
  while (fgets(line, sizeof(line), file)) {
		for(int i = 0; i < COLMAX; i++) {
      input[rowIndex][i] = line[i];
		}
		rowIndex++;
	}
  fclose(file);
}

int isLowPoint(int row, int col) {
  int isLow = 1;
  int current = input[row][col];

  // check above
  if (row != 0) {
    if (input[row-1][col] < current) {
      isLow = 0;
    }
  }

  // check right
  if (col != COLMAX-1) {
    if (input[row][col+1] <= current) {
      isLow = 0;
    }
  }

  // check below
  if (row != ROWMAX-1) {
    if (input[row+1][col] <= current) {
      isLow = 0;
    }
  }

  // check left
  if (col != 0) {
    if (input[row][col-1] <= current) {
      isLow = 0;
    }
  }

  return isLow;
}

// Function to check if we should visit a cell or not
int isValid(int vis[][COLMAX], int row, int col)
{
  if (row < 0 || col < 0 || row >= ROWMAX || col >= COLMAX) {
    return 0;
  };

  if (vis[row][col]) {
    return 0;
  };

  if (input[row][col] - '0' == 9) {
    return 0;
  }

  return 1;
}

struct Queue {
  int front, rear, size;
  unsigned capacity;
  struct Pair* array;
};

struct Queue* createQueue(unsigned capacity)
{
  struct Queue* queue = (struct Queue*)malloc(
      sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;

  queue->rear = capacity -1;
  queue->array = (struct Pair*)malloc(
      queue->capacity * sizeof(struct Pair));
  return queue;
}

int isFull(struct Queue* queue)
{
  return (queue-> size == queue-> capacity);
}

int isEmpty(struct Queue* queue)
{
  return (queue-> size == 0);
}

void enqueue(struct Queue* queue, struct Pair item)
{
  if (isFull(queue))
    return;
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;
}

struct Pair dequeue(struct Queue* queue)
{
  if (isEmpty(queue)) {
    struct Pair p = { .first = INT_MIN, .second = INT_MIN };
    return p;
  };

  struct Pair item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size = queue->size -1;
  return item;
}

struct Pair front(struct Queue* queue)
{
  if (isEmpty(queue)){
    struct Pair p = { .first = INT_MIN, .second = INT_MIN };
    return p;
  }
  return queue->array[queue->front];
}

struct Pair rear(struct Queue* queue)
{
  if (isEmpty(queue)){
    struct Pair p = { .first = INT_MIN, .second = INT_MIN };
    return p;
  }
  return queue->array[queue->rear];
}

void BFS(int grid[ROWMAX][COLMAX], int vis[ROWMAX][COLMAX], int row, int col)
{
  struct Queue *q = createQueue(100);
  struct Pair p = { .first = row, .second = col };
  enqueue(q, p);
  vis[row][col] = 1;

  while (isEmpty(q) == 0) {
    struct Pair p;
    int x = p.first;
    int y = p.second;

    printf("%i ", grid[x][y] - '0');

    p = dequeue(q);

    // Go to adjacent cells
    for (int i = 0; i < 4; i++) {
      int adjx = x + dRow[i];
      int adjy = y + dCol[i];
      if (isValid(vis, adjx, adjy)) {
        struct Pair p = { .first = adjx, .second = adjy };
        enqueue(q, p);
        vis[adjx][adjy] = 1;
      }
    }
  }
}

void part1()
{
  parseInput();
  for(int row = 0; row < ROWMAX; row++) {
    for(int col = 0; col < COLMAX; col++) {
      if (isLowPoint(row,col) == 1) {
        finalResult += (input[row][col] - '0' + 1);
        count++;
      }
    }
  }
  printf("Count: %i\n", count);
  printf("Final Result: %i\n", finalResult);
}

void part2()
{
  parseInput();
  memset(vis, 0, sizeof(vis));
  BFS(input, vis, 0, 1);
}

int main()
{
  part1();
  part2();
}
