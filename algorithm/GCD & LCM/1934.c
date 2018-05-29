#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char** argv)
{
	int N, N1, N2;
	int a, b;
	int temp;
	int res;
	int gcd = 0, lcm=0;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &N1, &N2);
		a = N1;
		b = N2;
		while (1) {
			if (a < b) {
				temp = a;
				a = b;
				b = temp;
			}
			res = a % b;
			a = b;
			b = res;
			if (res == 0) {
				gcd = a;
				break;
			}
		}
		lcm = abs(N1*N2) / gcd;
		printf("%d\n", lcm);
	}

	return 0;
}