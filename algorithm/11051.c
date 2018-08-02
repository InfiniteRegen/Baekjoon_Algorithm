#include <stdio.h>

int DP[1001][1001];
int main(int argc, char** argv)
{
	int N, K;

	scanf("%d %d", &N, &K);

	DP[0][0] = 1;
	DP[1][0] = 1;
	DP[1][1] = 1;

	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= K; ++j) {
			DP[i][j] = (DP[i - 1][j - 1] % 10007) + (DP[i - 1][j] % 10007);
			DP[i][j] %= 10007;
		}
	}

	printf("%d\n", DP[N][K]);

	return 0;
}