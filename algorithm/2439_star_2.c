#include <stdio.h>

int main(int argc, char** argv)
{
	int N = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if ((i + j) >= N - 1) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}