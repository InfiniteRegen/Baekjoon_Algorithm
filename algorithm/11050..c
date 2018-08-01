#include <stdio.h>

int main(int argc, char** argv)
	int N, K;
	int FactorialN = 1, FactorialK = 1, FactorialNK = 1;

	scanf("%d %d", &N, &K);

	if (K < 0) {
		printf("0\n");
		return 0;
	}
	else if (N < K) {
		printf("0\n");
		return 0;
	}
	else {
		for (int i = 1; i <= (N-K); ++i) {
			FactorialNK *= i;
		}
		for (int i = 1; i <= N; ++i) {
			FactorialN *= i;
		}
		for (int i = 1; i <= K; ++i) {
			FactorialK *= i;
		}
	}

	printf("%d\n", FactorialN / (FactorialK * FactorialNK));


	return 0;
}