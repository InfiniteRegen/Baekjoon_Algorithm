#include <stdio.h>

int main(int argc, char** argv)
{
	int input, sum;

	for (int j = 0; j < 3; ++j) {
		input = 0, sum = 0;

		for (int i = 0; i < 4; ++i) {
			scanf("%d", &input);
			sum += input;
		}

		switch (sum) {
			case 0:
				printf("D\n");
				break;
			case 1:
				printf("C\n");
				break;
			case 2:
				printf("B\n");
				break;
			case 3:
				printf("A\n");
				break;
			case 4:
				printf("E\n");
				break;
		}
	}

	return 0;
}