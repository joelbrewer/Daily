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

struct SNode {
  char data[100];
  struct SNode* next;
};

int pathsCount = 0;

struct Graph {
  int v;                    // Number of vertices in the graph
  struct Node** adjLists;   // Storing a pointer to struct node*, since
                            // we don't know how many vertices the graph
                            // will have and cannot create an array of
                            // Linked Lists at compile time
};

struct SNode *head = NULL;

int allowedDouble = 1;
int allowedDoubleUsed = 0;

struct Node* createNode(int v)
{
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = v;
  newNode->next = NULL;
  return newNode;
}

struct SNode* createSNode(char v[])
{
  struct SNode* newNode = malloc(sizeof(struct SNode));
  strcpy(newNode->data, v);
  newNode->next = head;
  head = newNode;
  return newNode;
}

int valueExists(char v[])
{
  struct SNode *ptr = head;
  while(ptr != NULL) {
    if(strcmp(ptr->data, v) == 0) {
      return 1;
    }
    ptr = ptr->next;
  }
  return 0;
}

void printList()
{
  struct SNode *ptr = head;
  while(ptr != NULL) {
    printf("%s\n", ptr->data);
    ptr = ptr->next;
  }
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

void printAllPathsUtil(
    struct Graph* graph,
    int u,
    int d,
    int visited[],
    int path[],
    int pathIndex,
    int v)
{
  // printf("printAllPathsUtil\n");

  visited[u] = 1;
  // Check to see if the current spot is a big cave,
  // in which case we can visit it more than once
  // if (u == 5 || u == 8 || u == 10) {
  if (u == 1) {
    visited[u] = 0;
  }

  if (u == allowedDouble && allowedDoubleUsed < 2) {
    visited[u] = 0;
    allowedDoubleUsed++;
  }

  // if (u == currentAllowedDouble && usedDouble == 0 ) {
  //   printf("currently allowed double: %d\n", currentAllowedDouble);
  //   printf("u: %d\n", u);
  //   visited[u] = 0;
  //   usedDouble = 1;
  // }

  path[pathIndex] = u;
  pathIndex++;

  if(u == d) {
    char p[100] = { '0' };
    for (int i = 0; i < pathIndex; i++) {
      char s[10];
      sprintf(s,"%d",path[i]);
      strcat(p, s);
    }

    if (valueExists(p) == 0) {
      createSNode(p);
      pathsCount++;
    }

  } else {
    struct Node* temp = graph->adjLists[u];
    while (temp) {
      if (visited[temp->data] != 1) {
        printAllPathsUtil(graph, temp->data, d, visited, path, pathIndex, v);
      }
      temp = temp->next;
    }
  }

  pathIndex--;
  visited[u] = 0;
}

void addPaths(struct Graph* graph, int v, int s, int d)
{

  for(int i = 2; i < v-1; i++) {
    allowedDoubleUsed = 0;
    allowedDouble++;

    int visited[v];
    memset(visited, 0, sizeof(visited));

    int path[v];
    memset(path, 0, sizeof(path));

    int pathIndex = 0;

    printf("Print paths allowing %d twice\n", allowedDouble);
    printAllPathsUtil(graph, s, d, visited, path, pathIndex, v);
  }
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
  printf("Start adding edges\n");
  // Print graph
  // Traverse graph
  // Print output
  //
  // Edges for test case
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 4);
  addEdge(graph, 1, 5);
  addEdge(graph, 2, 5);
  // 
  // Edges
  // addEdge(graph, 1, 0);
  // addEdge(graph, 2, 0);
  // addEdge(graph, 3, 4);
  // addEdge(graph, 5, 12);
  // addEdge(graph, 6, 2);
  // addEdge(graph, 4, 12);
  // addEdge(graph, 8, 2);
  // addEdge(graph, 1, 2);
  // addEdge(graph, 5, 3);
  // addEdge(graph, 3, 6);
  // addEdge(graph, 1, 8);
  // addEdge(graph, 1, 4);
  // addEdge(graph, 5, 4);
  // addEdge(graph, 8, 3);
  // addEdge(graph, 9, 12);
  // addEdge(graph, 9, 8);
  // addEdge(graph, 10, 3);
  // addEdge(graph, 4, 6);
  // addEdge(graph, 8, 4);
  // addEdge(graph, 0, 8);
  // addEdge(graph, 1, 5);
  // addEdge(graph, 11, 3);
  // addEdge(graph, 9, 6);
  addPaths(graph, 6, 0, 5);
  printList();
  printf("Paths count : %d", pathsCount);
  return 0;
}
