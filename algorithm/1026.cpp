#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

int N;
int S;
int A[50] = { 0, }, B[50] = { 0, };

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; ++i) {
		scanf("%d", &B[i]);
	}

	std::sort(A, A + N, std::greater<int>());
	std::sort(B, B + N);

	S = 0;
	for (int i = 0; i < N; ++i) {
		S += (A[i] * B[i]);
	}
	printf("%d\n", S);

	return 0;
}