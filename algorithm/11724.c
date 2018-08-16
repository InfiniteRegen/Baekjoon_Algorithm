#include <stdio.h>

int map[1001][1001];
int visited[1001];

int N, M;
int counter;

void DFS(int x)
{
	visited[x] = 1;
	for (int i = 1; i <= N; ++i) {
		if (map[x][i] && !visited[i]) {
			DFS(i);
		}
	}

	return;
}

int main()
{
	int x, y;

	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i) {
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
		map[y][x] = 1;
	}

	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			++counter;
			DFS(i);
		}
	}
	printf("%d\n", counter);

	return 0;
}