#include <stdio.h>

int main(int argc, char** argv)
{
	int N = 0;
	long long start = 0, end = 0;
	long long distance = 0;
	long long rangeStart = 0, rangeEnd = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%lld %lld", &start, &end);
		distance = end - start;
		
		for (long long j = 1;; ++j) {
			rangeStart = (j*j) - j + 1;
			rangeEnd = (j*j) + j;
			if (distance <= rangeEnd && rangeStart <= distance) {
				if ((j*j) >= distance) {
					printf("%lld\n", j * 2 - 1);
					break;
				}
				else {
					printf("%lld\n", j * 2);
					break;
				}
			}
		}
	}

	return 0;
}