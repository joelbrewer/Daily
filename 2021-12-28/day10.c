#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include "../lib/jlib.h"

struct Stack {
  int top;
  unsigned capacity;
  char* array;
};

struct Stack* createStack(unsigned capacity)
{
  // Note: we're dynamically allocating memory here. We're telling the compiler to dynamically
  // allocate enough memory to hold a Stack struct and then return a pointer of type Stack
  // to the newly allocated data.
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->capacity = capacity; // arrow operator allows access to members through a pointer var
  stack->top = -1;
  stack->array = (char*)malloc(stack->capacity * sizeof(char));
  return stack;
}

int isFull(struct Stack* stack)
{
  return stack->top == stack->capacity -1;
}

int isEmpty(struct Stack* stack)
{
  return stack->top == -1;
}

void push(struct Stack* stack, char item)
{
  if (isFull(stack)) {
    return;
  }
  stack->array[++stack->top] = item;
  printf("%c pushed to stack\n", item);
}

char pop(struct Stack* stack)
{
  if (isEmpty(stack)) {
    return '\0';
  }
  printf("%c popped from stack\n", stack->array[stack->top]);
  return stack->array[stack->top--];
}

char peek(struct Stack* stack)
{
  if (isEmpty(stack)) {
    return '\0';
  }
  return stack->array[stack->top];
}

void parseInput()
{
  char const* const fileName = "test10.txt";
  FILE* file = fopen(fileName, "r");
  char line[256];
  while (fgets(line, sizeof(line), file)) {
    struct Stack* stack = createStack(100);
    int c = 0;
    int i = 0;
    while ((c = line[i]) != '\n') {
      push(stack, c);
      i++;
    }
    free(stack);
	}
  fclose(file);
}

void part1()
{
  parseInput();
}

void part2()
{
}

int main()
{
  part1();
  part2();
}
