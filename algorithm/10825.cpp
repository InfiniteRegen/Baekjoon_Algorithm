#include <iostream>
#include <algorithm>

using namespace std;

struct scores {
	char name[11];
	int kor, eng, math;
};

struct scores input[100001];

bool cmp(struct scores a, struct scores b)
{
	if (a.kor < b.kor) return false;
	if (b.kor < a.kor) return true;

	if (a.eng < b.eng) return true;
	if (b.eng < a.eng) return false;

	if (a.math < b.math) return false;
	if (b.math < a.math) return true;

	char *first = a.name, *second = b.name;
	while (*first) {
		if (*first != *second)
			break;

		first++;
		second++;
	}
	return (((*first) - (*second)) < 0);

	return false;
}

int main()
{
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; ++i) {
		scanf("%s%d%d%d", input[i].name, &input[i].kor, &input[i].eng, &input[i].math);
	}
	
	sort(input, input + N, cmp);

	for (int i = 0; i < N; ++i) {
		printf("%s\n", input[i].name);
	}

	return 0;
}