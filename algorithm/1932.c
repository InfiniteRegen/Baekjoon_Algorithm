#include <cstdio>
#include <stdio.h>

#define MAX(a,b) (a>b) ? (a) : (b)

int input[501][501] = { 0 };

int main(int argc, char **argv)
{
	int N;
	int column = 1;
	int maxVal, max = -1;

	scanf("%d", &N);
	scanf("%d", &input[1][1]); // first level

	for (int row = 2; row <= N; ++row) { // starts loop with level 2

		while (column <= row) {

			scanf("%d", &input[row][column]);

			maxVal = MAX(input[row - 1][column - 1], input[row - 1][column]); // left vs. right comparison of before level
			input[row][column] += (maxVal);
			
			if (max < input[row][column]) { // check before column's maximum values.
				max = input[row][column];
			}
			++column;
		}
		column = 1;
	}

	printf("%d\n", max);

	return 0;
}