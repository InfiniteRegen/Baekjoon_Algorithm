#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int N, K, num;
int main()
{
	scanf("%d %d", &N, &K);
	v.resize(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	printf("%d\n", v[K-1]);
	return 0;
}