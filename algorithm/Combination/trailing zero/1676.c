#include <stdio.h>

int main(int argc, char** argv)
{
	int N = 0;
	int numOfTwo = 0 , numOfFive = 0;
	int operand = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; ++i) {
		if (i % 5 == 0) {
			operand = i;
			while (operand % 5 == 0) {
				operand /= 5;
				numOfFive++;
			}
		}

		if (i % 2 == 0) {
			operand = i;
			while (operand % 2 == 0) {
				operand /= 2;
				numOfTwo++;
			}
		}
	}
	printf("%d", (numOfTwo < numOfFive ? numOfTwo : numOfFive));
	return 0;
}