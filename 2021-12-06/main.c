#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"
#define NUMBITS 12

int day3part2();

struct node {
  char data[512];
  int key;
  struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void insertFirst(int key, char data[])
{
  struct node *link = (struct node*) malloc(sizeof(struct node));

  link->key = key;
  strcpy(link->data, data);

  link->next = head;

  head = link;
}

void printList()
{
  struct node *ptr = head;
  printf("\n[ ");

  while(ptr != NULL) {
    printf("%d,%s", ptr->key, ptr->data);
    ptr = ptr->next;
  }

  printf(" ]");
}

int length() {
  int length = 0;
  struct node *current;

  for(current = head; current != NULL; current = current->next) {
    length++;
  }

  return length;
}

struct node* delete(int key)
{
 //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}

// type: 0 for oxygent, 1 for co2
void filterList(int pos, int type)
{
  int lengthBefore = length();
  int count = 0; // bit count for current pos
  int bitToKeep = 0;
  for(current = head; current != NULL; current = current->next) {
    if (current->data[pos] - '0' == 1 ) {
      count += 1;
    }
  }

  if (type == 0 && count >= lengthBefore/2.0) {
    bitToKeep = 1;
  }

  if (type == 1 && count < lengthBefore/2.0) {
    bitToKeep = 1;
  }

  for(current = head; current != NULL; current = current->next) {
    if (current->data[pos] - '0' != bitToKeep) {
      delete(current->key);
    }
	}
}

int charToBinary(char a[])
{
  int v = 0;
  for(int i = 0; i < NUMBITS; i++) {
    if (a[NUMBITS-i-1] - '0' == 1) {
      v += pow(2,i);
    }
  }
  return v;
}

void buildLinkedList()
{
  int currentLine = 0;
  char const* const fileName = "input3.txt";
  FILE* file = fopen(fileName, "r");
  char line[512];
  while (fgets(line, sizeof(line), file)) {
    insertFirst(currentLine, line);
    currentLine++;
  }
}

int main()
{
  int o2 = 0;
  int co2 = 0;
  buildLinkedList();
	for (int i = 0; i < NUMBITS; i++) {
    if (length() > 1) {
      filterList(i, 0);
    }
  }

  o2 = charToBinary(head->data);

  delete(head->key);
  buildLinkedList();
	for (int i = 0; i < NUMBITS; i++) {
    if (length() > 1) {
      filterList(i, 1);
    }
  }
  co2 = charToBinary(head->data);
  printf("Life Support Rating: %d\n", o2*co2);
}


