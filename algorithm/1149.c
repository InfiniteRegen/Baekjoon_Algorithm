#include <stdio.h>
#include <math.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int input[1001][1001];
int minCost[1001][1001];

int main(int argc, char** argv)
{
	int N = 0;

	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= 3; ++j) {
			scanf("%d", &input[i][j]);
		}
	}

	minCost[1][1] = input[1][1];
	minCost[1][2] = input[1][2];
	minCost[1][3] = input[1][3];

	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j <= 3; ++j) {
			minCost[i][1] = MIN(minCost[i - 1][2], minCost[i - 1][3]) + input[i][1];
			minCost[i][2] = MIN(minCost[i - 1][1], minCost[i - 1][3]) + input[i][2];
			minCost[i][3] = MIN(minCost[i - 1][1], minCost[i - 1][2]) + input[i][3];
		}
	}

	printf("%d\n", MIN(minCost[N][1], MIN(minCost[N][2], minCost[N][3])));

	return 0;
}