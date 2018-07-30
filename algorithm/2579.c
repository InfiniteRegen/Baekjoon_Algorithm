#include <stdio.h> 

#define MAX(a,b) (a>b) ? (a) : (b)

int score[1000];
int dp[1000];

int main(int argc, char** argv)
{
	int N = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &score[i]);
	}

	dp[0] = score[0];
	dp[1] = MAX(score[0] + score[1], score[1]);
	dp[2] = MAX(score[0] + score[2], score[1] + score[2]);

	for (int i = 3; i < N; ++i) {
		dp[i] = MAX(dp[i - 2] + score[i], score[i - 1] + score[i] + dp[i - 3]);
	}

	printf("%d\n", dp[N - 1]);

	return 0;
}