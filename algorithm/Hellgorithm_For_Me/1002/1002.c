#include <stdio.h>
#include <math.h>

#define SQUARE(x) ((x)*(x))

int main(int argc, char** argv)
{
	int N;
	int x1, y1, r1;
	int x2, y2, r2;
	int x, y;
	int distance;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		x = abs(x2 - x1); y = abs(y2 - y1);
		distance = SQUARE(x) + SQUARE(y);

		if (distance == 0) {
			if (r1 == r2)
				printf("-1\n");
			else
				printf("0\n");
		}
		else if (distance < SQUARE(r1 + r2)) {
			if (SQUARE(r1 -r2) > distance ) {
				printf("0\n");
			}
			else if (SQUARE(r1-r2) == distance) {
				printf("1\n");
			}
			else if (SQUARE(r1-r2) < distance) {
				printf("2\n");
			}
		}
		else  if (distance > SQUARE(r1 + r2)) {
			printf("0\n");
		}
		else if (distance < SQUARE(r1 - r2)) {
			printf("0\n");
		}
		else if (distance == SQUARE(r1 + r2)) {
			printf("1\n");
		}
	}

	return 0;
}