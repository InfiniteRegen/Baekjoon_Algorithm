#include <iostream>
#include <cstdio>

using namespace std;

const int mx[4] = { 1, -1, 0, 0 };
const int my[4] = { 0, 0, 1, -1 };

char map[21][21] = { 0, };
int wordSet[26] = { 0, };

int R, C;
int maxVal = 0;

void DFS(int y, int x, int counter)
{
	int dx, dy;
	
	++counter;
	wordSet[map[y][x]]++;
	if (counter > maxVal)
		maxVal = counter;
	for (int i = 0; i < 4; ++i) {
		dx = mx[i] + x;
		dy = my[i] + y;
		if (dx < 1 || dy < 1 || dx > C || dy > R)
			continue;
		else
			if (!wordSet[map[dy][dx]])
				DFS(dy, dx, counter);
	}
	wordSet[map[y][x]] = 0;
	return;
}

int main()
{	
	scanf("%d %d", &R, &C);
	for (int y = 1; y <= R; ++y) {
		for (int x = 1; x <= C; ++x) {
			cin >> map[y][x];
			map[y][x] -= 'A';
		}
	}

	DFS(1, 1, 0);
	printf("%d\n", maxVal);
	return 0;
}