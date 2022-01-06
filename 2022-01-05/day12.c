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


int main()
{
  struct Graph* graph = createGraph(10);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 1, 2);
  printGraph(graph);
  return 0;
}
