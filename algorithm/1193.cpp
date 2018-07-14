#include <stdio.h>

int main(int argc, char** argv)
{
	int N;
	int x = 0, y = 0;
	int counter = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i) {
		if (i % 2 == 1) {
			x = i; y = 1;
		}
		else {
			y = i; x = 1;
		}
		++counter;
		
		while (counter != N) {
			if (i % 2 == 1) {
				if (x == 1)
					break;
				x--;
				y++;
			}
			else {
				if (y == 1)
					break;
				y--;
				x++;
			}
			++counter;
		}
		
		if (counter == N) {
			printf("%d/%d\n", x, y);
			return 0;
		}
	}

	return 0;
}