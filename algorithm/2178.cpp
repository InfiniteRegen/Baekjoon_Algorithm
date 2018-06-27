#include <stdio.h>
#include <queue>
using namespace std;

int N, M;
int map[100][100] = { 0, };
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };
void BFS(int x, int y);

int main(int argc, char** argv)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	map[0][0] = 2;
	BFS(0, 0);

	printf("%d\n", map[N - 1][M - 1] - 1);

	return 0;
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1)
				continue;

			if (map[nx][ny] == 1) {
				q.push(make_pair(nx, ny));
				map[nx][ny] = map[x][y] + 1;
			}
		}
	}

	return;
}