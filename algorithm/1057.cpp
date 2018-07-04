#include <stdio.h>

int main(int argc, char** argv)
{
	int N;
	int T, V;
	int counter = 0;

	scanf("%d %d %d", &N, &T, &V);

	if (T > N || V > N) {
		counter = -1;
	}
	else {
		while (T != V) {
			T = (1+T) / 2;
			V = (1+V) / 2;
			counter++;
		}
	}

	printf("%d\n", counter);

	return 0;
}