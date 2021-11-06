#include <stdio.h>

#define   IN     1
#define   OUT    0
#define   XMAX  127
#define   YMAX  20

/* Histogram of Char Frequencies*/

int main()
{
  int c, l, state;
  l = state = 0;
  int hist[XMAX+1][YMAX+1] = { 0 };
  int frequencies[XMAX] = { 0 };

  // Count the char frequencies
  while ((c = getchar()) != EOF) {
    ++frequencies[c];
  }

  // Add bars to histogram
  for (int i = 0; i < XMAX; i++) {
    int currentFrequency = frequencies[i];
    int currentCount = i + 1;
    if (currentFrequency > 0) {
      for (int j = 0; j < currentFrequency; j++) {
        hist[currentCount][j+1] = 1;
      }
    }
  }

  // Print the x axis
  for (int i = 1; i <= XMAX; i++) {
    hist[i][0] = i;
    // hist[0][i] = i;
  }


  for (int y = YMAX; y >= 0; y--) {
    for (int x = 0; x <= XMAX; x++) {
      c = hist[x][y];
      if (c == 0) {
        printf("    ");
      } else {
        printf("%02d", hist[x][y]);
      }
      if (x==XMAX) {
        printf("\n");
      }
    }
  }

  // Print the frequencies array
  printf("\n");
  for (int i = 0; i < XMAX; i++) {
    printf("%d", frequencies[i]);
  }

  return 0;
}
