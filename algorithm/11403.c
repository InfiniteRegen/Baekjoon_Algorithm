#include <stdio.h>

int map[101][101];
int visited[101][101];
int N;

void BFS(int bk, int x, int y)
{
	map[bk][y] = 1;
	visited[bk][y] = 1;

	for (int i = 1; i <= N; i++) {
		if (!visited[bk][i] && map[y][i]) {
			BFS(bk, y, i);
		}
	}

	return;
}

int main(int argc, char** argv)
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][i] && map[i][j])
				BFS(i, i, j);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}