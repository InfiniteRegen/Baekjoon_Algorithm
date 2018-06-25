#include <stdio.h>

const int units[6] = { 500, 100, 50, 10, 5, 1 };

int main(int argc, char** argv)
{
	int money, changes;
	int counter = 0;

	scanf("%d", &money);
	changes = 1000 - money;

	for (int i = 0; i < 6; ++i) {
		counter += (changes / units[i]);
		changes = (changes % units[i]);
	}
	
	printf("%d\n", counter);


	return 0;
}