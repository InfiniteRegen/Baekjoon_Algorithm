#include <stdio.h>
#include <string.h>

char input[50][51] = { 0, };
char output[51] = { 0, };

int main(int argc, char** argv)
{
	int N = 0, size, counter;
	int i, j;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", &input[i]);
	}
	size = strlen(input[0]);

	for (i = 0; i < size; ++i) {
		counter = 0;
		for (j = 0; j < N - 1; ++j) {
			if (input[j][i] == input[j + 1][i])
				counter++;
		}
		if (counter == N - 1)
			output[i] = input[j][i];
		else
			output[i] = '?';
	}
	output[size] = 0;
	printf("%s\n", output);
	return 0;
}