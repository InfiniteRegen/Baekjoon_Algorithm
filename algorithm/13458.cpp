#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int N, B, C;
	long long input = 0;
	vector<long long> v;
	long long total = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%lld", &input);
		v.push_back(input);
	}

	scanf("%d %d", &B, &C);

	for (int i = 0; i < v.size(); ++i) {
		total++;
		if (v[i] - B <= 0) {
			continue;
		}
		total += (v[i] - B) / C;
		
		if ((v[i] - B) % C != 0) {
			total++;
		}
	}
	printf("%lld\n", total);
	return 0;
}