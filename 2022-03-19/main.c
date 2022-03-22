#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void escape(char s[], char t[]) /* Converts chars like newline and tab into visible
                    escape sequences like \n and \t as it copies the 
                    string t to s 
                    Only supports \n and \t, but additional cases could be added*/
{
  int i, j;
  i = 0; // index of t
  j = 0; // index of s
  while (t[i] != '\0') {
    switch (t[i]) {
    case '\n':
      s[j] = '\\';
      ++j;
      s[j] = 'n';
      break;
    case '\t':
      s[j] = '\\';
      ++j;
      s[j] = 't';
      break;
    default:
      s[j] = t[i];
      break;
    }
    ++j;
    ++i;
  }
}

void descape(char s[], char t[]) /* Converts visible escape sequences 
                                    into actual escape sequences */
{
  int i, j;
  i = 0; // index of t
  j = 0; // index of s
  while (t[i] != '\0') {
    if(t[i] == '\\') {
      ++i;
      switch (t[i]) {
      case 'n':
        s[j] = '\n';
        break;
      case 't':
        s[j] = '\t';
        break;
      default:
        s[j] = t[i];
        break;
      }
      ++j;
      ++i;
    } else {
      s[j] = t[i];
      ++j;
      ++i;
    }
  }
}

/* What is a "statement" in C?
 *
 * "C statement consist of tokens, expressions, and other statements"
 *
 * x = 2;                   // An assignment statement
 * x = 2+3;                 // Another assignment statement
 * printf("Hello World");   // Statement containing a function call
 *
 * What is a token?
 *
 * What is an expression?
 *
 * An expression in C is a combination of operands and operators; it computes a single value 
 *
 * int d = (34 > 7) ? 1 : 0;
 * 2+2;
 *
 * An expression is something which evaluates to a value.
 * A statement is a line of code which does something.
 *
 * Operator: Indicates which action or operation to perform.
 * Operand: Indicates what items to to apply the action to.
 */

/* atoi: convert s to integer; version 2 */
int atoi(char s[])
{
  int i, n, sign;

  for (i = 0; isspace(s[i]); i++)
      ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (n = 0; isdigit(s[i]); i++)
    n = 10*n + (s[i] - '0');
  return sign * n;
}

/* shellsort: sort v[0]...v[n-1] into increasing order
 * See: https://www.youtube.com/watch?v=ddeLSDsYVp8&t=49s for more info
 */

void shellsort(int v[], int n)
{
  int gap, i, j, temp;

  for (gap = n/2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
        temp = v[j];
        v[j] = v[j+gap];
        v[j+gap] = temp;
      }
}

/* v: [888,5,79,4,33], [79,5,888,4,33]
 * n: 5
 * gap: 2
 * i: 2
 * j: 0
 * temp: 888
 *
 *
 *
 *
 */

int main()
{
  char t[100] = { 'H','e','l','l','o','\n','\t','W','o','r','l','d','\0'};
  char s[100];
  int v[10] = { 888, 90, 5, 4, 79, 3, 5, 2, 567, 88 };

  escape(s,t);
  printf("Result: %s\n", s);
  memset(s, 0, 100);
  descape(s,t);
  printf("Result: %s\n", s);
  printf("atoi(-123) %d\n", atoi("-123"));
  printf("atoi(-123)*10 %d\n", atoi("-123")*10);
  shellsort(v,10);
  for(int i=0;i<10;i++) {
    printf("%d", v[i]);

    if (i != 10-1) {
      printf(",");
    }
  }

  return 0;
}

/* Expands shorthand notation in the string s1 (eg: a-z) into
 * the corresponding complete list (abc...xyz) in s2
 */
void expand(char s1[], char s2[])
{

}

