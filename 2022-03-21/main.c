#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
/* Expands shorthand notation in the string s1 (eg: a-z) into
 * the corresponding complete list (abc...xyz) in s2
 */
void expand(char s1[], char s2[])
{

  int i = 0; // s1 index
  int j = 0; // s2 index
  int start = 0;
  int expanding = 0;
  while (s1[i] != '\0') {
    // First char of the range
    if (isalnum(s1[i]) && expanding == 0) {
      expanding = 1;
      start = s1[i];
      s2[j] = start;
      j++;
    // Last char of a range
    } else if (isalnum(s1[i]) && expanding == 1) {
      // start expanding
      for(int k=start+1;k<=s1[i];k++) {
        s2[j] = k;
        j++;
      }
      start = s1[i];
   // Leading '-'
     } else if (expanding == 0 && isalnum(s1[i]) == 0) {
       s2[j] = s1[i];
       j++;
   // Trailing '-'
     } else if (isalnum(s1[i]) == 0 && s1[i+1] == '\0') {
       s2[j] = s1[i];
       j++;
   // Middle '-'
    } else if (expanding == 1){
    }
    i++;
  }
}

int expandTest()
{
  int errors = 0;
  char after[100];
  expand("a-f", after);
  errors += strcmp(after, "abcdef");
  printf("errors : %d\n", errors);
  printf("after : %s\n", after);

  memset(after, 0, 100);
  expand("A-F", after);
  errors += strcmp(after, "ABCDEF");
  printf("errors : %d\n", errors);

  memset(after, 0, 100);
  expand("0-9", after);
  errors += strcmp(after, "0123456789");
  printf("errors : %d\n", errors);

  memset(after, 0, 100);
  expand("a-d-h", after);
  errors += strcmp(after, "abcdefgh");
  printf("errors : %d\n", errors);

  if (strcmp(after, "abcdefgh") != 0) {
    printf("Error : result : %s\n", after);
  }

  memset(after, 0, 100);
  expand("-a-d-h", after);
  errors += strcmp(after, "-abcdefgh");
  printf("errors : %d\n", errors);

  memset(after, 0, 100);
  expand("-a-d-h-", after);
  errors += strcmp(after, "-abcdefgh-");
  printf("errors : %d\n", errors);

  // TODO: This test doesn't currently pass
  memset(after, 0, 100);
  expand("a-z0-9", after);
  if (strcmp(after, "abcdefghijklmnopqrstuvwxyz0123456789") != 0) {
    printf("Error : result : %s\n", after);
  }

  return errors;
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

void itoa(long n, char s[])
{
  int i, sign;

  if ((sign = n) < 0) /* record sign */
    n = -n;
  i = 0;
  do { /* generate digits in reverse order */
    s[i++] = n % 10 + '0'; /* get next digit */
  } while ((n /= 10) > 0); /* delete it */
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  strrev(s);
}

// A machine word is the size (in bits) of data that the machine's CPU can handle optimally
// It is usually the same as the size of the processor's registers and addresses.
// It may vary between different architectures, but is typically 32 or 64 bits on modern
// machines.
int main()
{
  char s[1000];
  itoa(-pow(2,31),s);
  printf("itoa result : %s\n", s);
  return 0;
}

