#include <stdio.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int input[1000001];

int main(int argc, char** argv)
{
	int N = 0;

	scanf("%d", &N);

	for (int i = 2; i <= N; ++i) {
		input[i] = input[i - 1] + 1;
		if (i % 2 == 0) {
			input[i] = MIN(input[i], input[i / 2] + 1);
		}
		if (i % 3 == 0) {
			input[i] = MIN(input[i], input[i / 3] + 1);
		}
	}

	printf("%d\n", input[N]);

	return 0;
}