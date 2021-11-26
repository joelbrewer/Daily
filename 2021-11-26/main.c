#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../lib/jlib.h"
#define INPUT 600851475143L

struct node {
  int data;
  struct node* left;
  struct node* right;
};

void printArray(long a[]);
long largestPrimeFactor(long in);

struct node* newNode(long data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}


int main()
{
  long output = largestPrimeFactor(INPUT);
  printf("Input: %ld\n", INPUT);
  printf("Output: %ld\n", output);
  return 0;
}

long largestPrimeFactor(long n)
{
  long factor = 2;
  long remainder = n;
  struct node* root = newNode(n);
  struct node* current = root;
  while(remainder > 1) {
    factor = smallestPrimeFactor(remainder);
    remainder = remainder / factor;
    current->left = newNode(factor);
    current->right = newNode(remainder);
    current = current->right;
  }
  printf("Final factor : %ld\n", factor);
  return 0;
}

void printArray(long a[])
{
  // printf("sizeof : %ld\n", sizeof(*a));
  for(long i = 0; i < INPUT; i++) {
    printf("a[%ld] : %ld \n", i, a[i]);
  }
}
