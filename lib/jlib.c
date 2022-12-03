#include "jlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void reverse(char s[])
{
  char out[100];
  int c, i, j;
  i = 0;

  while ((c = s[i]) != '\0')
    i++;

  for (j = 0; j < i; j++) {
    out[j] = s[i-j-1];
  }

  copy(s, out);
}

void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

void insertFirst(int data, struct node **head_ref) {
   printf("insertFirst data : %d : pointer %p : head_ref\n", data, *head_ref);
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->data = data;
   link->next = *head_ref;
   *head_ref = link;
}

void printList(struct node **head_ref) {
   struct node *ptr = *head_ref;
   printf("\n[ ");
	
   while(ptr != NULL) {
      printf("(%d) ",ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

int length(struct node **head_ref) {
   int length = 0;
   struct node *current;
	
   for(current = *head_ref; current != NULL; current = current->next) {
      length++;
   }
   return length;
}

struct node* deleteFirst(struct node **head_ref) {

   struct node *tempLink = *head_ref;
	
   *head_ref = (*head_ref)->next;
	
   return tempLink;
}

void sort(struct node **head_ref) {

   int i, j, k, tempData;
   struct node *current;
   struct node *next;
	
   int size = length(head_ref);
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = *head_ref;
      next = (*head_ref)->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->data > next->data ) {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;
         }
         current = current->next;
         next = next->next;
      }
   }   
}

void reverseList(struct node **head_ref) {
   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
}
