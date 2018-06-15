#include <stdio.h>

#define TRUE  1
#define FALSE 0

int map[101][101];
int visited[101] = { 0, };
int count = 0;

void DFS(int startV, int N)
{
	count++;
	visited[startV] = TRUE;
	for (int i = 1; i <= N; ++i) {
		if (map[startV][i] == TRUE && visited[i] == FALSE) {
			DFS(i, N);
		}
	}

	return;
}

int main(int argc, char** argv)
{
	int N, M;
	int start, end;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= M; ++i) {
		scanf("%d %d", &start, &end);
		map[start][end] = TRUE;
		map[end][start] = TRUE;
	}

	DFS(1, N);

	printf("%d", count - 1);

	return 0;
}