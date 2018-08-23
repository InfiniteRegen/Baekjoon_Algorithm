#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
int main()
{
	int N;
	int x, y;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &x, &y);
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < (int)v.size(); ++i)
		printf("%d %d\n", v[i].first, v[i].second);

	return 0;
}