#include <stdio.h>

int Fibo(int n)
{
	int arr[3] = { 0, 1, 1 };
	for (int i = 2; i<n; i++) {
		arr[(i + 1) % 3] = arr[i % 3] + arr[(i - 1) % 3];
	}

	return arr[n % 3];
}

int main(int argc, char** argv)
{
	int N;

	scanf("%d", &N);
	printf("%d\n", Fibo(N));

	return 0;
}