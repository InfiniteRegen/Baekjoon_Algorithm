#include<stdio.h>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{
	int N, target;
	queue<int> q;

	scanf("%d %d", &N, &target);
	for (int i = 1; N >= i; i++) {
		q.push(i);
	}

	printf("<");
	while (!q.empty()) {
		for (int i = 0; i < target - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		printf("%d", q.front());
		q.pop();
		if (!q.empty()) {
			printf(", ");
		}

	}
	printf(">");

	return 0;
}