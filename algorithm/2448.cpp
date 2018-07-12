#include <stdio.h>
#include <vector>

using namespace std;

vector<char> v[10000];

void star(int n, int x, int y)
{
	if (n == 3) {
		v[y][x] = '*';

		v[y + 1][x - 1] = '*';
		v[y + 1][x + 1] = '*';

		v[y + 2][x - 2] = '*';
		v[y + 2][x - 1] = '*';
		v[y + 2][x] = '*';
		v[y + 2][x + 1] = '*';
		v[y + 2][x + 2] = '*';
	}
	else {
		star(n / 2, x, y);
		star(n / 2, x - n / 2, y + n / 2);
		star(n / 2, x - n / 2 + n, y + n / 2);
	}
}


int main(int argc, char** argv)
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			v[i].push_back(' ');
		}
	}

	star(n, n - 1, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			printf("%c", v[i][j]);
		}
		printf("\n");
	}
}
