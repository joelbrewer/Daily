#include <stdio.h>
#include <math.h>

int htoi(char s[]);
int hexCharToInt(int c);
int lower(int c);

int main()
{
  char input[] = { '0', 'x', '2','1','0' };
  printf("Input: %s\n", input);
  printf("Output: %d\n", htoi(input));
  return 0;
}

// Eg:
// Input    Output
// 0x110    272
int htoi(char s[])
{
  char c;
  int i = 0, j = 0, k = 0, o = 0;
  while((c = s[i]) != '\0')
      i++;
  for(j = i; j > 0; j--)
  {
    if (lower(s[j-1]) == 'x')
        break;
    o = o + pow(16, k)*hexCharToInt(s[j-1]);
    k++;
  }
  return o;
}

int lower(int c)
{
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else 
    return c;
}

int hexCharToInt(int c)
{
  c = lower(c);
  if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  } else {
    return c - '0';
  }
}
