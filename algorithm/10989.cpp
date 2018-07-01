#include <stdio.h>
#include <string.h>

using namespace std;

int input[10001] = { 0, };

int main(int argc, char** argv)
{
	int N;
	int num = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &num);
		input[num]++;
	}

	for (int i = 1; i <= 10000; i++) {
		if (input[i] > 0) {
			for (int j = 0; j < input[i]; ++j) {
				printf("%d\n", i);
			}
		}
	}

	return 0;
}