#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct scores {
	int country, gold, silver, bronze;
	int rank;
}scores_t;

int N, target;
scores_t input[1000];

int compare_score(scores_t first, scores_t second)
{
	if (first.gold < second.gold) return false;
	if (second.gold < first.gold) return true;

	if (first.silver < second.silver) return false;
	if (second.silver < first.silver) return true;

	if (first.bronze < second.bronze) return false;
	if (second.bronze < first.bronze) return true;

	return false;
}

int main()
{
	scanf("%d %d", &N, &target);

	for (int i = 0; i < N; ++i) {
		scanf("%d %d %d %d", &input[i].country, &input[i].gold, &input[i].silver, &input[i].bronze);
	}

	sort(input, input + N, compare_score);
	
	if (target == input[0].country) {
		printf("1\n");
		return 0;
	}
	input[0].rank = 1;
	for (int i = 1; i < N; ++i) {
		if (input[i].gold == input[i - 1].gold &&
			input[i].silver == input[i - 1].silver &&
			input[i].bronze == input[i - 1].bronze) {
			input[i].rank = input[i - 1].rank;
		}
		else {
			input[i].rank = i+1;
		}

		if (input[i].country == target) {
			printf("%d\n", input[i].rank);
		}
	}
	return 0;
}