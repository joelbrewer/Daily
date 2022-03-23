#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void itob(int n, char s[], int b);
char *strrev(char *str);

void itob(int n, char s[], int b) {
  int i, sign;

  if ((sign = n) < 0)
    n = -n;
  i = 0;

  do {
    int t = n % b;
    t += (t > 9) ? '0' + 7 : '0';
    s[i++] = t;
  } while ((n /= b) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  strrev(s);
}

int testitob(int n, int b, char e[])
{
  char after[100];
  itob(n, after, b);
  int result = strcmp(after,e);
  if(result != 0) {
    printf("Error, expected %s, got %s\n", e, after);
  } else {
    printf("Passed, expected %s, got %s\n", e, after);
  }
  return result;
}

char *strrev(char *str){
    char c, *front, *back;

    if(!str || !*str)
        return str;
    for(front=str,back=str+strlen(str)-1;front < back;front++,back--){
        c=*front;*front=*back;*back=c;
    }
    return str;
}

int main()
{
  testitob(16, 8, "20");
  testitob(32, 2, "100000");
  testitob(178, 16, "B2");
  return 0;
}

