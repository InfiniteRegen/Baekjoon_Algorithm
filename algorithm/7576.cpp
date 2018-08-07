#include <stdio.h>
#include <queue>

#define MAX_MAP_SIZE 1001

using namespace std;

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

int map[MAX_MAP_SIZE][MAX_MAP_SIZE] = { 0, };

int main(int argc, char** argv)
{
	int N, M;
	queue<pair<int, int>> q;
	pair<int, int> p1;
	int tomatoN = 0;

	int size = 0;
	int x, y;

	int days = 0;
	
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
			}
			else if (map[i][j] == 0) {
				tomatoN++;
			}
		}
	}

	if (tomatoN == 0) {
		printf("0\n");
		return 0;
	}

	while (!q.empty()) {
		days++;
		size = (int)q.size();
		for (int i = 0; i < size; ++i) {
			p1 = q.front();
			q.pop();
			for (int j = 0; j < 4; ++j) {
				x = mx[j] + p1.first;
				y = my[j] + p1.second;
				
				if (x < 1 || y < 1 || x > M || y > N) {
					continue;
				}
				else {
					if (map[x][y] == 0) {
						map[x][y] = 1;
						q.push(make_pair(x, y));
						--tomatoN;
					}
				}
			}
			
			if (tomatoN == 0) {
				printf("%d\n", days);
				return 0;
			}
		}
	}
	printf("-1\n");
	
	
	return 0;
}