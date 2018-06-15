#include <stdio.h>
#include <queue>

using namespace std;

#define TRUE  1
#define FALSE 0

int map[1001][1001];
int visitedDFS[1001] = { 0, };
int visitedBFS[1001] = { 0, };
queue<int> myQueue;

void DFS(int startV, int N)
{

	visitedDFS[startV] = 1;
	printf("%d ", startV);
	for (int i = 1; i <= N; ++i) {
		if (visitedDFS[i] == FALSE && map[startV][i] == TRUE) {
			DFS(i, N);
		}
	}

	return;
}

void BFS(int startV, int N)
{
	int pop;

	printf("%d ", startV);
	myQueue.push(startV);
	visitedBFS[startV] = TRUE;

	while (!myQueue.empty()) {
		pop = myQueue.front();
		myQueue.pop();

		for (int i = 1; i <= N; ++i) {
			if (map[pop][i] == TRUE && visitedBFS[i] == FALSE) {
				printf("%d ", i);
				myQueue.push(i);
				visitedBFS[i] = TRUE;
			}
		}
	}
	return;
}

int main(int argc, char** argv)
{
	int N = 0, M = 0, V = 0;
	int start, end;

	scanf("%d %d %d", &N, &M, &V);

	for (int i = 1; i <= M; ++i) {
		scanf("%d %d", &start, &end);
		map[start][end] = 1;
		map[end][start] = 1;
	}

	/* Algorithms for DFS */
	DFS(V, N);
	printf("\n");
	/* Algorithms for BFS */
	BFS(V, N);

	return 0;
}