#include <stdio.h>

int numbers[1000];

int main(int argc, char** argv) {

	int N = 0;
	int count = 0;
	int divNum = 1;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &numbers[i]);
	}

	for (int i = 0; i < N; i++) {
		divNum = 1;
		if (numbers[i] == 1) {
			count++;
			continue;
		}

		while (divNum*divNum <= numbers[i]) {
			if (divNum == 1) {
				divNum++;
				continue;
			}

			if (numbers[i] % divNum == 0) {
				count++;
				break;
			}
			divNum++;
		}
	}

	printf("%d", N - count);	

	return 0;
}