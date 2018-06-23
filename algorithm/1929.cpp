#include <stdio.h>
#include <math.h>

int arr[1000001];

int main(int argc, char** argv)
{
	int x, y;
	int j;

	scanf("%d %d", &x, &y);

	for (int i = 0; i < y + 1; ++i) {
		arr[i] = 1;
	}

	for (int i = 2; i < y + 1; i++) {

		if (arr[i]) {

			if ((unsigned int)pow((double)i, (double)2) > 1000001) {
				break;
			}
			else {
				for (j = (int)pow((double)i, (double)2); j < y + 1;) {
					arr[j] = 0;
					j += i;
				}
			}

		}
	}

	if (x == 1)
		++x;

	for (int i = x; i < y + 1; ++i) {
		if (arr[i] && i >= x) 
			printf("%d\n", i);
	}

	return 0;
}