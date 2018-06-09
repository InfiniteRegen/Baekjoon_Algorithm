#include <stdio.h>

int Calculate(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;

	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char** argv)
{
	int N = 0, M = 0;
	int minimum = 0;
	int sum = 0;

	scanf("%d %d", &N, &M);

	for (int i = N; i <= M; i++) {
		if (Calculate(i)) {
			if (minimum == 0) {
				minimum = i;
				sum += i;
			}
			else{
				sum += i;
			}
		}
	}

	if (minimum == 0) {
		printf("-1");
		return 0;
	}
	
	printf("%d\n", sum);
	printf("%d\n", minimum);
	
	return 0;
}