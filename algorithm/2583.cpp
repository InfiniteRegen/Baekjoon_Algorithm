#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int mx[4] = { 1, -1, 0, 0 };
const int my[4] = { 0, 0, 1, -1 };

int map[101][101] = { 0, };
int M, N, K;
int counter = 0;

void DFS(int y, int x)
{
	int dx, dy;

	counter++;
	map[y][x] = 2;

	for (int i = 0; i < 4; ++i) {
		dx = mx[i] + x;
		dy = my[i] + y;
		if (dy < 0 || dx < 0 || dy >= M || dx >= N)
			continue;
		else if (map[dy][dx] == 0) {
			DFS(dy, dx);
		}
	}

	return;
}

int main(int argc, char** argv)
{
	int LeftX, LeftY;
	int RightX, RightY;
	std::vector<int> v;

	scanf("%d %d %d", &M, &N, &K);

	int x, y;
	for (int k = 0; k < K; ++k) {
		scanf("%d %d %d %d", &LeftX, &LeftY, &RightX, &RightY);
		
		for (int i = LeftY; i < RightY; ++i) {
			for (int j = LeftX; j < RightX; ++j) {
				map[i][j] = 1;
			}
		}	
	}

	for (int y = 0; y < M; ++y) {
		for (int x = 0; x < N; ++x) {
			if (map[y][x] == 0) {
				DFS(y, x);
				v.push_back(counter);
				counter = 0;
			}
		}
	}

	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (auto i : v) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}