typedef struct node node;;
extern long smallestPrimeFactor(long n);
extern int isPrime(long n);
void copy(char to[], char from[]);
void reverse(char s[]);
void reverseList(struct node **head_ref);
void printList(struct node **head_ref);
void insertFirst(int data, struct node **head_ref);
int length(struct node **head_ref);
struct node* deleteFirst(struct node **head_ref);
void sort(struct node **head_ref);

struct node {
  int data;
  struct node *next;
};
