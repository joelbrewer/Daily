#include <stdio.h>

void increase(int x[]);
void funWithPointers();
void moreFunWithPointers();

int main() {
  char x;
  int i;
  short s;
  char y;
  int a[5] = { 1, 2, 3, 4, 5 };

  printf("x is allocated at %p \n", &x);
  printf("i is allocated at %p \n", &i);
  printf("s is allocated at %p \n", &s);
  printf("y is allocated at %p \n", &y);

  printf("a[1] : %d \n", a[1]);
  increase(a);
  printf("a[1] : %d \n", a[1]);
  //funWithPointers();
  moreFunWithPointers();
}

void increase(int x[]) {
  x[1] = 50;
}

void funWithPointers() {
  int y, z;
  int *p;

  y = 7;
  p = &y;   // pointer p now points to y
  z = *p;   // give z the value of what p points to
            // aka dereference p

  printf("y : %d \n", y);
  printf("p : %p \n", p);
  printf("z : %d \n", z);
}

void moreFunWithPointers() {
  int a, b, c;
  int *x, **y, *z;

  a = 1;
  x = &a;
  printf("x is %p \n", x);
  (*x)++;
  printf("a is %d \n", a);
  y = &x;
  (**y)++;
  printf("a is now: %d \n", a);
  *x = 1; // equal to a = 1
  printf("a is now: %d \n", a);
}
