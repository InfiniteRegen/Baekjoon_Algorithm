#include <stdio.h>

int position[3] = { 1, 0, 0 };

void Swap(int *a, int *b)
{
	int temp;
	temp = position[*a-1];
	position[*a-1] = position[*b-1];
	position[*b-1] = temp;

	return;
}

int main(int argc, char** argv)
{
	int N;
	int x, y;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &x, &y);
		Swap(&x, &y);
	}
	
	for (int i = 0; i < 3; ++i) {
		if (position[i] == 1) {
			printf("%d", i + 1);
		}
	}


	return 0;
}