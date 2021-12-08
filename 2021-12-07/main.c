#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/jlib.h"
#define CARDSIZE 5

typedef struct {
	int value;
	int status;
} space;

struct board {
	space s[5][5];
};

int checkForBingo(struct board b)
{
	// check horizontals
	for (int row = 0; row < CARDSIZE; row++) {
		int inRow = 0;
    for (int col = 0; col < CARDSIZE; col++) {
			if (b.s[row][col].status == 1) {
				inRow++;
      }
			if (inRow == 5) {
				return 1;
			}
		}
  }
	return 0;
	// check verticals
  // check diagnols
}


int main()
{
	struct board b;
	b.s[0][0] = (space) { .value = 22, .status = 1 };
	b.s[0][1] = (space) { .value = 13, .status = 1 };
	b.s[0][2] = (space) { .value = 17, .status = 1 };
	b.s[0][3] = (space) { .value = 11, .status = 1 };
	b.s[0][4] = (space) { .value = 0,  .status = 0 };

	b.s[1][0] = (space) { .value = 8,  .status = 0 };
	b.s[1][1] = (space) { .value = 2,  .status = 0 };
	b.s[1][2] = (space) { .value = 23, .status = 0 };
	b.s[1][3] = (space) { .value = 4,  .status = 0 };
	b.s[1][4] = (space) { .value = 24, .status = 0 };

	b.s[2][0] = (space) { .value = 21, .status = 0 };
	b.s[2][1] = (space) { .value = 9,  .status = 0 };
	b.s[2][2] = (space) { .value = 14, .status = 0 };
	b.s[2][3] = (space) { .value = 16, .status = 0 };
	b.s[2][4] = (space) { .value = 7,  .status = 0 };

	b.s[3][0] = (space) { .value = 6,  .status = 0 };
	b.s[3][1] = (space) { .value = 10, .status = 0 };
	b.s[3][2] = (space) { .value = 3,  .status = 0 };
	b.s[3][3] = (space) { .value = 18, .status = 0 };
	b.s[3][4] = (space) { .value = 5,  .status = 0 };

	b.s[4][0] = (space) { .value = 1,  .status = 0 };
	b.s[4][1] = (space) { .value = 12, .status = 0 };
	b.s[4][2] = (space) { .value = 20, .status = 0 };
	b.s[4][3] = (space) { .value = 15, .status = 0 };
	b.s[4][4] = (space) { .value = 19, .status = 0 };
	int result = checkForBingo(b);
	printf("Result : %d\n", result);

}


