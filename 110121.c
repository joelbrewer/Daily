// Should probably review some documentation on writing linked lists in C.
// Working off of Java examples is helpful, but pretty tricky since I haven't covered
// C fundamentals in a while!
// 
// OR, I could work the The C Programming Language first (probably a better idea)
#include <stdio.h>

struct IntNode {
  int data;
  struct IntNode *link;
};

static struct IntNode head;
static struct IntNode tail;

struct IntNode initializeIntNode(int initialData, struct IntNode *initialLink) {
  struct IntNode node;
  node.data = initialData;
  node.link = initialLink;
  return node;
};

int getData(struct IntNode *node) {
  return node->data;
}

struct IntNode getLink(struct IntNode *node) {
  return *node->link;
}

static void setData(struct IntNode *node, int data) {
  node->data = data;
};

static void setLink(struct IntNode *node, struct IntNode link) {
  node->link = &link;
};

static void addAtHead(int data) {
  head = initializeIntNode(data, head.link);
  // struct IntNode new = initializeIntNode(data, head.link);
  // head->data = data; // Hmm, this is overwriting the data...
  // head->link = head->link;
}

// static void addNodeAfter(int element) { }
// static void getData() { }
// static void getLink() { }
// static void getLink() { }


int main() {
  struct IntNode initialLinkNode;
  initialLinkNode.data = 0;
  initialLinkNode.link = 0;

  head = initializeIntNode(2020, &initialLinkNode);
  addAtHead(2019);
  addAtHead(2018);
  // tail = initializeIntNode(2021, 0);
  // addAtHead(5);
  // addAtHead(6);
  printf("Head Data : %i", getData(&head));
  printf("\n");
  // printf("Head Link : %i", getData(getLink(&head)));
  printf("Link data : %i", getData(head.link));
  // printf("Next Data : %i", getData(head.link));
  // struct list_node node;
  // node.data = 1;
  // printf("Head Data : %i", getData(head));
  // setData(&head, 2030);
  // printf("\n");
  // printf("Head Data : %i", getData(head));
  // printf("\n");
  // printf("Head Link : %i", getLink(head));
  // printf("\n");
  // printf("Tail Data : %i", getData(tail));
  // printf("\n");
  // printf("Tail Link : %i", getLink(tail));
  return 0;
}

