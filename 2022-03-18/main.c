#include <stdio.h>
#include <time.h>

void escape(char s[], char t[]) /* Converts chars like newline and tab into visible
                    escape sequences like \n and \t as it copies the 
                    string t to s */
{
  int i, j;
  i = 0; // index of t
  j = 0; // index of s
  while (t[i] != '\0')
    switch (t[i]) {
    case '\n':
      // printf("matched!");
      s[j] = '\\';
      ++j;
      s[j] = 'n';
      ++j;
      ++i;
      break;
    default:
      // printf("matched default");
      s[j] = t[i];
      ++j;
      ++i;
      break;
    }
}
int main()
{
  char t[12] = { 'H','e','l','l','o','\n','W','o','r','l','d','\0'};
  char s[13];
  escape(s,t);
  printf("Result: %s \n", s);
}
