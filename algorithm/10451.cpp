#include <stdio.h>
#include <string.h>

#define TRUE  1
#define FALSE 0

int T, N;
int map[1001][1001];
int visited[1001][1001];
int counter = 0;

void DFS(int x, int y)
{
	visited[x][y] = TRUE;

	for (int j = 1; j <= N; ++j) {
		for (int k = 1; k <= N; ++k) {
			if (map[j][k] && !visited[j][k]) {
				DFS(j, k);
			}
		}
	}

	return;
}

int main(int argc, char** argv)
{
	int number;

	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		scanf("%d", &N);
		counter = 0;
		memset(map, 0x00, sizeof(map));
		memset(visited, 0x00, sizeof(visited));

		for (int j = 1; j <= N; ++j) {
			scanf("%d", &number);
			map[j][number] = TRUE;
			map[number][j] = TRUE;
		}

		for (int j = 1; j <= N; ++j) {
			for (int k = 1; k <= N; ++k) {
				if (map[j][k] && !visited[j][k]) {
					DFS(j, k);
				}
			}
		}
		
		printf("%d\n", counter);

	}
	return 0;
}