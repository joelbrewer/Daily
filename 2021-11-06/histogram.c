#include <stdio.h>

#define   IN     1
#define   OUT    0
#define   XYMAX  20

/* Histogram of Word Length Frequencies*/

int main()
{
  int c, l, state;
  l = state = 0;
  int hist[XYMAX+1][XYMAX+1] = { 0 };
  int frequencies[XYMAX] = { 0 };

  // Count the word frequencies
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      if (l != 0) {
        ++frequencies[l-1];
      }
      l = 0;
    } else if (state == OUT) {
      state = IN;
      l++;
    } else {
      l++;
    }
  }

  // Add bars to histogram
  for (int i = 0; i < XYMAX; i++) {
    int currentFrequency = frequencies[i];
    int currentCount = i + 1;
    if (currentFrequency > 0) {
      for (int j = 0; j < currentFrequency; j++) {
        hist[currentCount][j+1] = 11;
      }
    }
  }

  // Print the x and y axis
  for (int i = 1; i <= XYMAX; i++) {
    hist[i][0] = i;
    hist[0][i] = i;
  }


  for (int y = XYMAX; y >= 0; y--) {
    for (int x = 0; x <= XYMAX; x++) {
      c = hist[x][y];
      if (c == 0) {
        printf("    ");
      } else {
        printf(" %02d ", hist[x][y]);
      }
      if (x==XYMAX) {
        printf("\n");
      }
    }
  }

  // Print the frequencies array
  // printf("\n");
  // for (int i = 0; i < XYMAX; i++) {
  //   printf("%d", frequencies[i]);
  // }

  return 0;
}

