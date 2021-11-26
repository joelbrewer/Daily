#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INPUT 30L

struct node {
  int data;
  struct node* left;
  struct node* right;
};

long sieve();
void printArray(long a[]);
void crossOut(long current, long a[]);
long smallestPrimeFactor(long in);
long largestPrimeFactor(long in);
int isPrime(long in);

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

// Eg:
// Input    Output
// 30       29
long sieve()
{
  long nums[INPUT] = { 0 };
  long current = 2;
  while(current*current < INPUT) {
    crossOut(current, nums);
    for(long i = current+1; i < INPUT; i++) {
      if (nums[i] == 0) {
        break;
      }
    }
    printArray(nums);
    break;
    // need to grab the next highest number that hasn't been crossed off
  }
  return 0;
}

void crossOut(long current, long nums[])
{
  for(long i = current, j = i*current; j < INPUT; i++) {
    nums[j] = 1;
    j = i*current;
  }

}

int isPrime(long n)
{
  if (n <= 3){
    return n > 1;
  }
  if (n%2 == 0 || n % 3 == 0) {
    return 0;
  }
  int i = 5;
  while(pow(i, 2) <= n) {
    if (n % i == 0 || n % (i+2) == 0) {
      return 0;
    }
    i += 6;
  }
  return 1;
}

long smallestPrimeFactor(long n)
{
  for(long i = 2; i < n; i++) {
    if (isPrime(i) == 1 && (n%i == 0) ) {
      return i;
    }
  }
  return n;
}

long largestPrimeFactor(long n)
{
  long factor = 2;
  long remainder = n;
  struct node* root = newNode(n);
  struct node* current = root;
  while(remainder > 1) {
    printf("Factor : %ld\n", factor);
    factor = smallestPrimeFactor(n);
    remainder = n / factor;
    current->left = newNode(factor);
    current->right = newNode(remainder);
    current = current->right;
  }
  return 0;
}

void printArray(long a[])
{
  // printf("sizeof : %ld\n", sizeof(*a));
  for(long i = 0; i < INPUT; i++) {
    printf("a[%ld] : %ld \n", i, a[i]);
  }
}


// Store n as root of tree
// Find smallest prime factor (start with 2, then go up by prime numbers)
// Store that number in one branch
// Store the quotient in the other branch
// Repeat the above for the quotient until you obtain 1 as the factor for the remaining number
