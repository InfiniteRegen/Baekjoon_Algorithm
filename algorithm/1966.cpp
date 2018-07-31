#include <stdio.h>
#include <queue>

using namespace std;

int main(int argc, char**argv)
{
	int N;
	int M, P, counter;
	int temp;
	int first = 0, second = 0 ;
	queue <pair<int, int>> q;
	priority_queue <int> priQ;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		counter = 0;
		q = queue<pair<int, int>>();
		priQ = priority_queue <int>();

		scanf("%d %d", &M, &P);
		for (int j = 0; j < M; ++j) {
			scanf("%d", &temp);
			q.push(make_pair(j, temp));
			priQ.push(temp);
		}

		while (!q.empty()) {
			first = q.front().first;
			second = q.front().second;
			q.pop();

			if (priQ.top() == second) {
				priQ.pop();
				counter++;
				if (first == P) {
					printf("%d\n", counter);
					break;
				}
			}
			else {
				q.push(make_pair(first, second));
			}
		}
	}

	return 0;
}