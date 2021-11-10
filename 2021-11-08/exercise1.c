#include <stdio.h>

int main (void)
{
  short i = 0x1234;
  char x = -127;
  long sn1 = 3147537260;
  long sn2 = 8157426285;
  int y[2] = {0x11223344,0x44332211};

  printf("Size of i : %d \n", i);
  printf("i is allocated at: %p \n", &i);

  printf("address\t\t\tcontent (hex)\t\tcontent (dec) \n");
  printf("----------------------------------------------------- \n");
  printf("%p\t\t%d", &i, i);
}
