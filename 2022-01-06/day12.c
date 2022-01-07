#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include "../lib/jlib.h"
#define COLMAX 10
#define ROWMAX 10

struct Node {
  int data;
  struct Node* next;
};

int pathsCount = 0;

struct Graph {
  int v; // Number of vertices in the graph
  struct Node** adjLists; // Storing a pointer to struct node*, since
                          // we don't know how many vertices the graph
                          // will have and cannot create an array of
                          // Linked Lists at compile time
};

struct Node* createNode(int v)
{
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int vertices)
{
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->v = vertices;
  graph->adjLists = malloc(vertices * sizeof(struct Node*));

  for (int i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
  }
  return graph;
}

void addEdge(struct Graph* graph, int s, int d)
{
  struct Node* newNode = createNode(d);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;

  newNode = createNode(s);
  newNode->next = graph->adjLists[d];
  graph->adjLists[d] = newNode;
}

void printGraph(struct Graph* graph)
{
  for (int v = 0; v < graph->v; v++) {
    struct Node* temp = graph->adjLists[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

void printAllPathsUtil(struct Graph* graph, int u, int d, int visited[], int path[], int pathIndex)
{

  visited[u] = 1;
  if (u == 5 || u == 8 || u == 10) {
    visited[u] = 0;
  }

  path[pathIndex] = u;
  pathIndex++;

  if(u == d) {
    for (int i = 0; i < pathIndex; i++) {
      printf("%d ", path[i]);
    }
    pathsCount++;
    printf("\n");
  } else {
    struct Node* temp = graph->adjLists[u];
    while (temp) {
      if (visited[temp->data] != 1) {
        printAllPathsUtil(graph, temp->data, d, visited, path, pathIndex);
      }
      temp = temp->next;
    }
  }

  pathIndex--;
  visited[u] = 0;
}

void printPaths(struct Graph* graph, int v, int s, int d)
{
  int visited[v];
  memset(visited, 0, sizeof(visited));

  int path[v];
  memset(path, 0, sizeof(path));

  int pathIndex = 0;

  printAllPathsUtil(graph, s, d, visited, path, pathIndex);
}

void parseInput()
{
  char const* const fileName = "test12.txt";
  FILE* file = fopen(fileName, "r");
  char line[256];
  char *firstV;
  char *secondV;
  while (fgets(line, sizeof(line), file)) {
    firstV = strtok(line, "-");
    secondV = strtok(NULL,"-");
    printf("first %s\n", firstV);
    printf("second %s\n", secondV);

	}
  fclose(file);
}



int main()
{
  struct Graph* graph = createGraph(13);
  // Print graph
  // Traverse graph
  // Print output
  //
  // Edges for test case
  // addEdge(graph, 0, 1);
  // addEdge(graph, 0, 2);
  // addEdge(graph, 1, 3);
  // addEdge(graph, 1, 2);
  // addEdge(graph, 2, 4);
  // addEdge(graph, 1, 5);
  // addEdge(graph, 2, 5);
  // 
  // Edges
  printf("Start adding edges\n");
  addEdge(graph, 1, 0);
  addEdge(graph, 2, 0);
  addEdge(graph, 3, 4);
  addEdge(graph, 5, 12);
  addEdge(graph, 6, 2);
  addEdge(graph, 4, 12);
  addEdge(graph, 8, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 5, 3);
  addEdge(graph, 3, 6);
  addEdge(graph, 1, 8);
  addEdge(graph, 1, 4);
  addEdge(graph, 5, 4);
  addEdge(graph, 8, 3);
  addEdge(graph, 9, 12);
  addEdge(graph, 9, 8);
  addEdge(graph, 10, 3);
  addEdge(graph, 4, 6);
  addEdge(graph, 8, 4);
  addEdge(graph, 0, 8);
  addEdge(graph, 1, 5);
  addEdge(graph, 11, 3);
  addEdge(graph, 9, 6);
  printPaths(graph, 13, 0, 12);
  printf("Paths count : %d", pathsCount);
  return 0;
}
