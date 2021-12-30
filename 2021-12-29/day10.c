#include <stdio.h>
#include <assert.h>
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

struct node {
  long data;
  struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void insertFirst(long data)
{
  struct node *link = (struct node*) malloc(sizeof(struct node));

  link->data = data;
  link->next = head;
  head = link;
}

void printList()
{
  struct node *ptr = head;
  printf("\n[ ");

  while(ptr != NULL) {
    printf("%ld ", ptr->data);
    ptr = ptr->next;
  }

  printf(" ]");
}

long getNth(struct node* head, int index)
{
	struct node* current = head;
  int count = 0;
  while (current != NULL) {
    if (count == index)
      return (current->data);
    count++;
    current = current->next;
  }
  assert(0);
}

int length() {
  int length = 0;
  struct node *current;

  for(current = head; current != NULL; current = current->next) {
    length++;
  }

  return length;
}

struct node* newNode(long data)
{
    struct node* new_node = (struct node*)malloc( sizeof(struct node));
  
    new_node->data = data;
    new_node->next = NULL;
  
    return new_node;
}

void sortedInsert(struct node** head_ref,
                  struct node* new_node)
{
    struct node* current;
    /* Special case for the head end */
    if (*head_ref == NULL
        || (*head_ref)->data
               >= new_node->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        /* Locate the node before 
the point of insertion */
        current = *head_ref;
        while (current->next != NULL
               && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

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

int getPointValue2(char c)
{
  switch(c) {
    case '(' :
      return 1;
    case '[' :
      return 2;
    case '{' :
      return 3;
    case '<' :
      return 4;
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
  char const* const fileName = "input10.txt";
  FILE* file = fopen(fileName, "r");
  char line[256];
  while (fgets(line, sizeof(line), file)) {
    struct Stack* stack = createStack(100);
		int incomplete = 1;
    int c = 0;
    int i = 0;
    while ((c = line[i]) != '\n') {
      if (isOpen(c) != -1) {
        push(stack, c);
      } else {
        if (isMatch(c, stack) == 0) {
					incomplete = 0;
          break;
        } else {
          pop(stack);
        }
      }
      i++;
    }
    if (incomplete == 1) {
      long score = 0;
      while(isEmpty(stack) != 1) {
        score = score * 5;
        score = score + getPointValue2(peek(stack));
        pop(stack);
      }
			sortedInsert(&head, newNode(score));
    }
    free(stack);
	}

  int mid = length()/2;
  printf("Final Score: %ld\n", getNth(head, mid));
  fclose(file);
}

int main()
{
  part1();
  part2();
}
