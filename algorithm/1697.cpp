#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int visited[100001] = { false, };
int position[3] = { -1, 0, 1 };

int Move(int K, int N)
{
	int pos, counter;
	int next;
	queue<pair<int, int>> q;
	visited[N] = 1;
	q.push(pair<int, int>(N, 0));

	while (!q.empty()) {
		pos = q.front().first;
		counter = q.front().second;
		q.pop();

		if (pos == K) {
			return counter;
		}

		for (int i = 0; i < 3; i++) {
			
			if (position[i] != 0) {
				next = pos + position[i];
			}
			else {
				next = pos * 2;
			}
			if (0 <= next && next <= 100000) {
				if (!visited[next]) {
					q.push(pair<int, int>(next, counter + 1));
					visited[next] = true;
				}
			}
		}
	}
	return 0;
}

int main(int argc, char** argv)
{
	int N, K;

	scanf("%d %d", &N, &K);

	if (K <= N) {
		printf("%d", N - K);
	}
	else {
		printf("%d\n", Move(K, N));
	}
    
	return 0;
}
