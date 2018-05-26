#include <stdio.h>

#define SUM(x) x + x%10 + (x/10)%10 + (x/100)%10 + x/1000

int result[10000];

int main(int argc, char** argv)
{
	for (int n = 1; n < 10000; ++n)
		result[SUM(n)]++;

	for (int n = 1; n < 10000; ++n) {
		if (result[n] == 0)
			printf("%d\n", n);
	}

	return 0;
}