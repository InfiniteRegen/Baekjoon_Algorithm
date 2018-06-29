#include <stdio.h>

int main(int argc, char** argv)
{
	int X, Y;
	int divider = 64, sum = 0, counter = 0;

	scanf("%d", &X);
	Y = X;
	while (Y != sum) {
		if (X < divider) {
			divider /= 2;
		}
		else {
			if (divider == 1) {
				counter += (Y - sum);
				break;
			}
			sum += divider;
			counter++;
			X %= divider;
			if (X % divider == 0 && X / divider == 1) {
				counter = 1;
				break;
			}
			X %= divider;
		}
	}

	printf("%d", counter);
	return 0;
}