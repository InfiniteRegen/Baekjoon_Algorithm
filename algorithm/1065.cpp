#include <stdio.h>

int main(int argc, char** argv)
{
	int N;
	int k, t, a[3], res;
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i) {
		if (i < 100) {
			res = i;
		}
		else if ( i== 1000) {
			break;
		}
		else  {
			k = 0;
			t = i;
			while (t>0) {
				a[k] = t % 10;
				t /= 10;
				k++;
			}
			if (a[0] - a[1] == a[1] - a[2])
				res++;
		}
	}
	printf("%d", res);
	return 0;
}