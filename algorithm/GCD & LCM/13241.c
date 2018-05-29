#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	long long int N1, N2;
	long long int a, b;
	long long int temp;
	long long int res;
	long long int gcd = 0, lcm = 0;

	scanf("%lld %lld", &N1, &N2);
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
	lcm = N1*N2 / gcd;
	printf("%lld\n", lcm);

	return 0;
}