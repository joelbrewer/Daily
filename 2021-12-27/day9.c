#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include "../lib/jlib.h"
#define COLMAX 10
#define ROWMAX 10
#define LOWPOINTS 247

int finalResult = 0;
int count = 0;
int input[ROWMAX][COLMAX];
int vis[ROWMAX][COLMAX];
int basinSizes[LOWPOINTS];

int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

struct Pair {
  int first;
  int second;
};

struct Pair lowPoints[LOWPOINTS];

void parseInput()
{
  char const* const fileName = "test11.txt";
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

int BFS(int grid[ROWMAX][COLMAX], int vis[ROWMAX][COLMAX], int row, int col)
{
  int size = 1;
  struct Queue *q = createQueue(100);
  struct Pair p = { .first = row, .second = col };
  enqueue(q, p);
  vis[row][col] = 1;

  while (isEmpty(q) == 0) {
    struct Pair p;
    p = dequeue(q);
    int x = p.first;
    int y = p.second;

    // printf("%i ", grid[x][y] - '0');

    // Go to adjacent cells
    for (int i = 0; i < 4; i++) {
      int adjx = x + dRow[i];
      int adjy = y + dCol[i];
      if (isValid(vis, adjx, adjy)) {
        struct Pair p = { .first = adjx, .second = adjy };
        enqueue(q, p);
        size++;
        vis[adjx][adjy] = 1;
      }
    }
  }
  return size;
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++) {

		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] > arr[min_idx])
				min_idx = j;

		// Swap the found minimum element
		// with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}

void part1()
{
  parseInput();
  for(int row = 0; row < ROWMAX; row++) {
    for(int col = 0; col < COLMAX; col++) {
      if (isLowPoint(row,col) == 1) {
        finalResult += (input[row][col] - '0' + 1);
        struct Pair p = { .first = row, .second = col };
        lowPoints[count] = p;
        count++;
      }
    }
  }
  printf("Count: %i\n", count);
  printf("Part 1 Final Result: %i\n", finalResult);
}

void part2()
{
  for(int i = 0; i < LOWPOINTS; i++) {
    memset(vis, 0, sizeof(vis));
    int s = BFS(input, vis, lowPoints[i].first, lowPoints[i].second);
    basinSizes[i] = s;
  }
  int n = sizeof(basinSizes) / sizeof(basinSizes[0]);

	selectionSort(basinSizes, n); 

  int final = 1;

  for (int i = 0; i < 3; i++) {
    final = final * basinSizes[i];
  }
  printf("Part 2 Final Result: %i\n", final);
}

int main()
{
  printf("before parse");
  parseInput();
  printf("after parse");
  for (int i = 0; i < ROWMAX; i++) {
    for (int j = 0; j < COLMAX; j++) {
      printf("%d", input[i][j]);
      if (j == COLMAX-1)
        printf("\n");
    }
  }
  // part1();
  // part2();
}
