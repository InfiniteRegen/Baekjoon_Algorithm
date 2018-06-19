#include <stdio.h>
#include <string.h>

#define TRUE  1
#define FALSE 0

int M, N, K;
int map[51][51] = { 0 };
int visited[51][51] = { 0 };

int coor_y[4] = { 1, -1, 0, 0 };
int coor_x[4] = { 0, 0, 1, -1 };

void DFS(int y, int x)
{
	for (int i = 0; i < 4; i++) {
		int _y = y + coor_y[i];
		int _x = x + coor_x[i];

		if (_y < 0 || _y >= N || _x < 0 || _x >= M)
			continue;

		if (map[_y][_x] && !visited[_y][_x]) {
			visited[_y][_x]++;
			DFS(_y, _x);
		}
	}

	return;
}

int main(int argc, char** argv)
{
	int T = 0;
	int x = 0, y = 0;
	int result = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		result = 0;
		scanf("%d %d %d", &M, &N, &K);

		memset(map, 0x00, sizeof(map));
		memset(visited, 0x00, sizeof(visited));
		
		for (int j = 0; j < K; ++j) {
			scanf("%d %d", &x, &y);
			map[y][x] = TRUE;
		}

		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				if (map[j][k] && !visited[j][k]){
					result++;
					visited[j][k]++;
					DFS(j, k);
				}
			}
		}

		printf("%d\n", result);
	}

	return 0;
}