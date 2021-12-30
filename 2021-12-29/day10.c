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

void print(struct Stack* stack)
{
  if (isFull(stack)) {
    return;
  }

  printf("stack: ");
  for(int i = 0; i < stack->top; i++) {
    printf("%c ", stack->array[i]);
  }
}

void push(struct Stack* stack, char item)
{
  if (isFull(stack)) {
    return;
  }
  stack->array[++stack->top] = item;
}

char pop(struct Stack* stack)
{
  if (isEmpty(stack)) {
    return '\0';
  }
  return stack->array[stack->top--];
}

int any(char s1[], char s2[])
{
  char c, c2;
  int i = 0; // Length of s2
  int j = 0; // Current index of s1
  int matchedIndex = -1; // Index of first matching char

  while ((c = s2[i]) != '\0') {
    i++;
  }

  while ((c2 = s1[j]) != '\0') {
    for (int k = 0; k < i; k++) {
      if (c2 == s2[k]) {
        matchedIndex = j;
        break;
      }
    }
    if (matchedIndex != -1) {
      break;
    }
    j++;
  }
  return matchedIndex;
}

char peek(struct Stack* stack)
{
  if (isEmpty(stack)) {
    return '\0';
  }
  return stack->array[stack->top];
}

int isOpen(char c)
{
  char open[] = "([{<";
  char input[] = { c, '\0' };
  return any(open, input);
}

int isMatch(char c, struct Stack* stack)
{
  char c2 = peek(stack);
  int output = 0;
  switch(c) {
    case ')' :
      if (c2 == '(')
        output = 1;
      break;
    case '}' :
      if (c2 == '{')
        output = 1;
      break;
    case '>' :
      if (c2 == '<')
        output = 1;
      break;
    case ']' :
      if (c2 == '[')
        output = 1;
      break;
    default :
      output = 0;
  }
  return output;
}

int getPointValue(char c)
{
  switch(c) {
    case ')' :
      return 3;
    case '}' :
      return 1197;
    case '>' :
      return 25137;
    case ']' :
      return 57;
    default :
      return 0;
  }
}

void part1()
{
  char const* const fileName = "input10.txt";
  FILE* file = fopen(fileName, "r");
  char line[256];
  int total = 0;
  while (fgets(line, sizeof(line), file)) {
    struct Stack* stack = createStack(100);
    int c = 0;
    int i = 0;
    while ((c = line[i]) != '\n') {
      if (isOpen(c) != -1) {
        push(stack, c);
      } else {
        if (isMatch(c, stack) == 0) {
          total = total + getPointValue(c);
          break;
        } else {
          pop(stack);
        }
      }
      i++;
    }
    free(stack);
	}
  printf("Total : %d\n", total);
  fclose(file);
}

void part2()
{
}

int main()
{
  part1();
  part2();
}
