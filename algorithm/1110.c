#include <stdio.h>

#define TENS(x) x/10
#define ONES(x) x%10

int main(int argc, char** argv)
{
	int originalNumber=0, cycle = 0;
	int count = 0;
	int sum = 0;
	scanf("%d", &originalNumber);

	cycle = originalNumber;

	while (1) {
		++count;
		sum = TENS(cycle) + ONES(cycle);
		cycle = ONES(cycle)*10 + ONES(sum);
		if (cycle == originalNumber) break;
	}
	printf("%d", count);

	return 0;
}