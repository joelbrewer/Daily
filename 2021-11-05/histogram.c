#include <stdio.h>

#define   IN    1
#define   OUT   0
#define   XMAX  10
#define   YMAX  10
#define		WORDLENGTHMAX 10

void printHistogram(int xMax, int yMax, char hist[][YMAX+1])
{
  for (int y = yMax; y >= 0; y--) {
    for (int x = 0; x <= xMax; x++) {
      printf("%c", hist[x][y]);
      if (x == 10) {
        printf("\n");
      }
    }
  }
}

int main()
{
  int wordLengthFrequencies[WORDLENGTHMAX] = { 0 };
	int c, wl, state;
  wl = 0;
	state = OUT;
  // Dynamically allocate based on word length
  // with most occurances (y) and longest word (x)
  char hist[XMAX+1][YMAX+1] = { ' ' };

  // Set X scale
  for (int i = 1; i < XMAX; i++) {
		printf("Setting hist[i][0] to %c\n", i + '0');
		printf("i is: %d\n", i);
    hist[i][0] = i + '0';
  }

  // Set Y scale
  for (int i = 1; i < YMAX; i++) {
		printf("Setting hist[0][i] to %c\n", i + '0');
		printf("i is: %d\n", i);
    hist[0][i] = i + '0';
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
			if (wl != 0) {
			  printf("Increment!\n");
				++wordLengthFrequencies[wl-1];
			}
			wl = 0;
		} else if (state == OUT) {
			state = IN;
			++wl;
		} else {
			++wl;
		}
  }
	
	for (int i = 1; i < WORDLENGTHMAX; i++) {
		printf("%d : %d\n", i, wordLengthFrequencies[i-1]);
	}
	
	for (int i = 1; i < WORDLENGTHMAX; i++) {
		for (int j = 1; j <= wordLengthFrequencies[i]; j++) {
			// hist[i+2][j] = 'X';
		}
	}
 	
	// hist[3][1] = 'X';


	

  // hist[0][1] = 'X';
  // hist[0][2] = 'X';
  // hist[0][3] = 'X';
  // hist[0][4] = 'X';
  // hist[1][0] = 'X';
  // hist[2][0] = 'X';
  // hist[3][0] = 'X';
  // hist[4][0] = 'X';
  printHistogram(XMAX, YMAX, hist);

}


// 4 X
// 3 X
// 2 X X
// 1 X X 
//   1 2 3 4 5 6 7 
