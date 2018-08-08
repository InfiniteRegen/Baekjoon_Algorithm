#include <stdio.h>
#include <queue>

const int mz[6] = { 1, -1, 0, 0, 0, 0 };
const int mx[6] = { 0, 0, 1, -1, 0, 0 };
const int my[6] = { 0, 0, 0, 0, 1, -1 };

int map[101][101][101] = { 0, };

struct coordinate {
	int z;
	int x;
	int y;
};

int main(int argc, char** argv)
{
	int N, M, H;
	std::queue<coordinate> q;
	coordinate cd;
	int tomatoN = 0;
	int days = 1;

	scanf("%d %d %d", &N, &M, &H);
	for (int k = 1; k <= H; ++k) {
		for (int i = 1; i <= M; ++i) {
			for (int j = 1; j <= N; ++j) {
				scanf("%d", &map[k][i][j]);

				if (map[k][i][j] == 0) {
					tomatoN++;
				}
				else if (map[k][i][j] == 1) {
					q.push({ k, i, j });
				}
			}
		}
	}

	if (tomatoN == 0) {
		printf("0\n");
		return 0;
	}

	int size = 0;
	int x, y, z;
	while (!q.empty()) {
		size = q.size();
		for (int i = 0; i < size; ++i) {
			cd = q.front();
			q.pop();
			for (int j = 0; j < 6; ++j) {
				z = mz[j] + cd.z;
				x = mx[j] + cd.x;
				y = my[j] + cd.y;

				if (x < 1 || y < 1 || z < 1 ||
					x > M || y > N || z > H) {
					continue;
				}
				else {
					if (map[z][x][y] == 0) {
						map[z][x][y] = 1;
						tomatoN--;
						q.push({ z, x, y});
					}
					if (tomatoN == 0) {
						printf("%d\n", days);
						return 0;
					}
				}
			}
		}
		days++;
	}

	printf("-1\n");

	return 0;
}