#include <stdio.h>
#include <time.h>
#include <string.h>

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

int main()
{
  char t[100] = { 'H','e','l','l','o','\n','\t','W','o','r','l','d','\0'};
  char s[100];
  escape(s,t);
  printf("Result: %s\n", s);
  memset(s, 0, 100);
  descape(s,t);
  printf("Result: %s\n", s);
  return 0;
}
