#include <stdio.h>

int cal(int num)
{
	int sum = num;
	while (num != 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int main(int argc, char** argv)
{
	int n;
	
	scanf("%d", &n);
	for (int i = 1; i <= 1000000; i++) {
		if (cal(i) == n) {
			printf("%d\n", i);
			return 0; 
		}
	}

	printf("0\n");
	return 0;
}