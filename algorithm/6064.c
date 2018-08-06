#include <stdio.h>

int LCM(int n1, int n2)
{
	int i, gcd, lcm;

	for (i = 1; i <= n1 && i <= n2; ++i) {
		if (n1%i == 0 && n2%i == 0)
			gcd = i;
	}

	lcm = (n1*n2) / gcd;
	
	return lcm;
}

int main(int argc, char** argv)
{
	int T = 0;
	int M, N;
	int target_x, target_y, target;
	int counter = 0;
	int lcm;
	int small = 0, big = 0, accumlator = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		scanf("%d %d %d %d", &M, &N, &target_x, &target_y);
		lcm = LCM(M, N);
		
		if (M > N) {
			small = N;
			big = M;
			counter = target_y;
			target = target_x;
			accumlator = target_y;
		}
		else {
			small = M;
			big = N;
			counter = target_x;
			target = target_y;
			accumlator = target_x;
		}
		
		while (1) {
			if (accumlator == target) {
				printf("%d\n", counter);
				break;
			}
			if (counter > lcm) {
				printf("-1\n");
				break;
			}
			accumlator = (accumlator + small) % big;
			if (accumlator == 0) accumlator = big;
			counter += small;
		}

	}

	return 0;
}