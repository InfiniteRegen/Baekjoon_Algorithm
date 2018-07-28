#include <stdio.h>

int main(int argc, char** argv)
{
	int N, M;
	int a, b, c, d;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {

		scanf("%d", &M);

		if (M == 1) {
			printf("1\n");
		}
		else if (M == 2) {
			printf("2\n");
		}
		else if (M == 3) {
			printf("4\n");
		}
		else {
			a = 1, b = 2, c = 4, d = 0;
			for (int i = 0; i < M - 3; ++i) {
				d = a + b + c;
				a = b;
				b = c;
				c = d;
			}
			printf("%d\n", c);
		}
	}

	return 0;
}