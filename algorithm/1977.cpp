#include <stdio.h>
#include <set>

using namespace std;

int main(int argc, char** argv)
{
	int N, M;
	int sum = 0;
	set<int> s;

	scanf("%d %d", &N, &M);

	for (int i = N; i <= M; ++i) {
		for (int j = 1; j*j <= i; ++j) {
			if (j*j == i) {
				s.insert(i);
				sum += i;
			}
		}
	}
	if (s.empty() == 1) {
		printf("-1\n");
	}
	else {
		printf("%d\n%d", sum, *(s.begin()));
	}
	return 0;
}