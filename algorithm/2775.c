#include <stdio.h>

int Calculation(int x, int y)
{
	if (x == 0) 
		return 1;
	else if (y == 0) 
		return x + 1;
	else
		return Calculation(x - 1, y) + Calculation(x, y - 1);
}

int main(int argc, char** argv)
{
	int N;
	int floor, room;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &floor, &room);
		printf("%d\n", Calculation(room - 1, floor));
	}
	return 0;
}