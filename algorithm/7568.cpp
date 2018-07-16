#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int n;
	int x, y;
	vector<int> v[100];

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &x, &y);
		v[i].push_back(x);
		v[i].push_back(y);
		v[i].push_back(0);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) 
				continue;
			if (v[i][0] < v[j][0] && v[i][1] < v[j][1]) 
				v[i][2]++;
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", v[i][2] + 1);
	}

	return 0;
}
