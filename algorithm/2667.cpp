#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

#define TRUE  1
#define FALSE 0

using namespace std;

int T = 0;
int map[100][100] = { 0 };
int visited[100][100] = { 0 };

int coor_y[4] = { 1, -1, 0, 0 };
int coor_x[4] = { 0, 0, 1, -1 };

int counter = 0;

void DFS(int y, int x)
{
	counter++;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int _y = y + coor_y[i];
		int _x = x + coor_x[i];

		if (_y < 1 || _y > T || _x < 1 || _x > T)
			continue;

		if (map[_y][_x] && !visited[_y][_x]) {
			DFS(_y, _x);
		}
	}

	return;
}

int main(int argc, char** argv)
{
	vector<int> countSaver;
	char input[100] = { 0 };

	scanf("%d", &T);

	for (int i = 1; i <= T; ++i) {
		scanf("%s", input);
		for (int j = 1; j <= T; ++j) {
			map[i][j] = input[j - 1] - '0';
		}
	}
	
	for (int i = 1; i <= T; ++i) {
		for (int j = 1; j <= T; ++j) {
			if (!visited[i][j] && map[i][j]) {
				counter = 0;
				DFS(i, j);
				countSaver.push_back(counter);
			}
		}
	}

	sort(countSaver.begin(), countSaver.end());
	printf("%d\n", (int)(countSaver.size()));
	
	for (int i = 0; i < (int)(countSaver.size()); ++i) {
		printf("%d\n", (countSaver[i]));
	}


	return 0;
}