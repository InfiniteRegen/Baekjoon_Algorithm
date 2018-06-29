#include <stdio.h>

int main(int argc, char** argv)
{
	int in, out;
	int total = 0, max = 0;

	for (int i = 0; i < 4; ++i) {

		scanf("%d %d", &out, &in);
		total += (in - out);
		if (total > max) {
			max = total;
		}
	}

	printf("%d", max);

	return 0;
}