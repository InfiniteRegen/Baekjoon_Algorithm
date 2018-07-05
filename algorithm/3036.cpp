#include <stdio.h>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
	if (a < b)
		return GCD(a, b%a);
	if (b == 0)
		return a;
	
	GCD(b, a%b);
}

int main(int argc, char** argv)
{
	int N, element;
	int gcd;

	vector<int> v;
	
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &element);
		v.push_back(element);
	}

	for (int i = 1; i < N ; ++i) {
		gcd = GCD(v[0], v[i]);
		printf("%d/%d\n", v[0]/gcd, v[i]/gcd);
	}
	
	return 0;
}