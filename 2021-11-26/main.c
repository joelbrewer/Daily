#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"
#define INPUT 600851475143L

struct node {
  int data;
  struct node* left;
  struct node* right;
};

void printArray(long a[]);
long largestPrimeFactor(long in);
int isPalindrome(int n);
void largestPalindrome();
void smallestMultiple();

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
  char string[100];
  printf("Input: %ld\n", INPUT);
  sprintf(string,"%d",123);
  // printf("Output: %s\n", string);
  // largestPalindrome();
  smallestMultiple();
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

// Largest palindrome product (PE Problem 4)
void largestPalindrome()
{
  int largest = 0;
  int product;
  for(int i = 100; i < 1000; i++) {
    for(int j = 100; j < 1000; j++) {
      product = i*j;
      if (isPalindrome(product) == 0 && product > largest) {
        largest = product;
      }
    }
  }
  printf("Largest : %d", largest);
}

int isPalindrome(int n)
{
  char s[100] = { '0' };
  char r[100] = { '0' };
  sprintf(s,"%d",n);
  copy(r, s);
  reverse(r);
  return strcmp(s,r);
}

void smallestMultiple()
{
  int c = 20;
  while(1) {
    if (c % 1 == 0 &&
        c % 2 == 0 &&
        c % 3 == 0 &&
        c % 4 == 0 &&
        c % 5 == 0 &&
        c % 6 == 0 &&
        c % 7 == 0 &&
        c % 8 == 0 &&
        c % 9 == 0 &&
        c % 10 == 0 &&
        c % 11 == 0 &&
        c % 12 == 0 &&
        c % 13 == 0 &&
        c % 14 == 0 &&
        c % 15 == 0 &&
        c % 16 == 0 &&
        c % 17 == 0 &&
        c % 18 == 0 &&
        c % 19 == 0 &&
        c % 20 == 0) {
      printf("Answer : %d\n", c);
      break;
    } else {
      c++;
    }
  }
}

