#include <stdio.h>

int main(int argc, char** argv)
{
	long long a = 1, n, sum = 0;

	scanf("%d", &n);
	while (1) {
		sum += (a++);
		if (sum > n)
			break;
	}

	printf("%d\n", a - 2);

	return 0;
}