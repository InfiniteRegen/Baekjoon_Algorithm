#include <stdio.h>

int main(int argc, char** argv)
{
	long long N = 0, Factorial = 1;

	scanf("%lld", &N);
	if (N == 0) {
		printf("1\n");
		return 0;
	}

	for (long long i = 1; i <= N; ++i) {
		Factorial *= i;
	}

	printf("%lld\n", Factorial);

	return 0;
}