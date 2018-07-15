#include <stdio.h>

int main()
{
	int T, H, W, N;

	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d %d %d", &H, &W, &N);
		printf("%d\n", ((((N - 1) % H) + 1) * 100) + ((((N - 1) / H) + 1)));
	}

	return 0;
}