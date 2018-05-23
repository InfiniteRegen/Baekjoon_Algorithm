#include <stdio.h>
#include <string.h>

#define SUM(x) (x*(x+1)) / 2

int main(int argc, char** argv)
{
	int count = 0, score = 0;
	int N = 0, len = 0;

	char in[81];

	scanf("%d", &N);

	for (int k = 0; k < N; ++k) {
		score = 0, count = 0;
		scanf("%s", in);
		len = (int)strlen(in);

		for (int i = 0; i < len; ++i) {
			if (in[i] == 'X') {
				score += (SUM(count));
				count = 0;
			}
			else {
				++count;
			}
		}
		score += (SUM(count));
		printf("%d\n", score);
	}
	return 0;
}