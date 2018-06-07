#include <stdio.h>
#include <math.h>

int Sosu(int n)
{
	if (n == 1) {
		return 0;
	}
	else if (n == 2) {
		return 1;
	}
	for (int i = 2; i <= sqrt((double)n); i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main(int argc, char** argv)
{
	int num = 0;
	int n;

	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break; 

		num = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (Sosu(i)) {
				num++;
			}
		}
		printf("%d\n", num);
	}

	return 0;
}
