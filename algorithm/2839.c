#include <stdio.h>

int main(int argc, char** argv)
{
	int N = 0;

	scanf("%d", &N);

	for (int x = N / 5; x >= 0; --x) {
		if ((N - (x * 5)) % 3 == 0) {
			printf("%d", (N - (x * 5)) / 3 + x);
			return 0;
		}
	}

	printf("-1");

	return 0;
}