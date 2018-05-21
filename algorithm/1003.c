#include <stdio.h>
#include <stdlib.h>

int f[999999];
int max = -1;

void fib(int n)
{
	int i = 0;

	f[0] = 0;
	f[1] = 1;

	if (max >= n)
		return;

	max = n;
	/* Make Fibonacci Numbers */
	for (i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	return;
}

int main()
{
	int in = 0, i = 0,  n = 0;

	scanf("%d", &in);
	
	for (i = 0; i < in; ++i) {
		scanf("%d", &n);
		if (n == 0) {
			printf("1 0\n");
			continue;
		}
		if (n == 1) {
			printf("0 1\n");
			continue;
		}
		fib(n);
		printf("%d %d\n", f[n - 1], f[n]);
	}
	return 0;
}