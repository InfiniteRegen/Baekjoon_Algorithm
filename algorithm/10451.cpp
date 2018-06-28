#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<int> a[1001];
int chk[1001];
int ans;

void DFS(int node)
{
	chk[node] = 1;

	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (chk[next] != 1) {
			DFS(next);
		}
	}

	return;
}

int main(int argc, char** argv)
{
	int V;

	scanf("%d", &T);

	for (int k = 0; k < T; ++k) {

		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &V);
			a[i].push_back(V);
		}

		for (int i = 1; i <= N; i++) {
			if (chk[i] != 1) {
				DFS(i);
				ans++;
			}
		}

		printf("%d\n", ans);

		for (int i = 1; i <= N; i++) {
			fill(a[i].begin(), a[i].end(), 0);
		}
		memset(chk, 0, sizeof(chk));

		ans = 0;
	}

	return 0;
}