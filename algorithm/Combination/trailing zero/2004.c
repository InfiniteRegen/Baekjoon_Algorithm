#include <stdio.h>

int main(int argc, char** argv)
{
	int n = 0, m = 0, sub = 0;
	int numOfTwo = 0, numOfFive = 0;
	int zeroN = 0, zeroM = 0, zeroSub = 0;
	long long int i = 0;

	scanf("%d %d", &n, &m);
	if (m == 0 || n == m) {
		printf("0");
		return 0;
	}
	sub = n - m;

	for (i = 2; i <= n; i *= 2) {
		numOfTwo += (n / i);
	}

	for (i = 5; i <= n; i *= 5) {
		numOfFive += (n / i);
	}

	for (i = 2; i <= m; i *= 2) {
		numOfTwo -= (m / i);
	}

	for (i = 5; i <= m; i *= 5) {
		numOfFive -= (m / i);
	}

	for (i = 2; i <= sub; i *= 2) {
		numOfTwo -= (sub / i);
	}

	for (i = 5; i <= sub; i *= 5) {
		numOfFive -= (sub / i);
	}

	printf("%d\n", (numOfTwo < numOfFive ? numOfTwo : numOfFive));

	return 0;
}