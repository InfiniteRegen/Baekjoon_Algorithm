#include <stdio.h>
#include <string.h>

/* 2292.c */
int main(int argc, char** argv)
{
	int N;
	int mul = 1;
	int sum = 1;
	scanf("%d", &N);

	if (N == 1) {
		printf("1");
		return 0;
	}

	for (int i = 1;; i++, mul++) {
		if (sum >= N) {
			printf("%d", i);
			break;
		}
		sum += mul * 6;
	}

	return 0;
}