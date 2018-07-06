#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char** argv)
{
	int N, modMax = 0;
	double element, avg = 0.0, range = 0.0;
	vector<double> v;
	vector<int> modV;
	set<int> s;
	
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%lf", &element);
		avg += element;
		v.push_back(element);
	}

	avg /= N;
	printf("%.0lf\n", avg);

	sort(v.begin(), v.end());
	printf("%.0lf\n", v[N/2]);

	range = v[N - 1] - v[0];

	modV.assign(8010, 0);

	for (int i = 0; i < N; ++i) {
		modV[v[i] + 4000]++;
	}

	for (int i = 0; i < 8010; ++i) {
		if (modMax < modV[i]) {
			modMax = modV[i];
			s.clear();
			s.insert(i-4000);
		}
		else if (modMax == modV[i]) {
			s.insert(i-4000);
		}
	}

	set<int>::iterator iter = s.begin();

	if (s.size() == 1) {
		printf("%d\n", *(iter));
	}
	else {
		iter++;
		printf("%d\n", *iter);
	}
	printf("%.0lf\n", range);


	return 0;
}