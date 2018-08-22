#include <cstdio>
#include <cstring>
#include <algorithm>

#define ENGNUM 26

using namespace std;

struct inputs {
	char data[31];
	short *pWordCounter;
};


char wordSet[ENGNUM] = { 0, };
short wordCounter[ENGNUM] = { 0, };

struct inputs input[20];

bool comp(struct inputs first, struct inputs second)
{
	char *a = first.data, *b = second.data;

	while (*a && *b) {
		if (*a != *b)
			return wordCounter[(*a) - 'A'] < wordCounter[(*b) - 'A'];
		a++;
		b++;
	}

	return (strlen(first.data) < strlen(second.data));
}

int main()
{
	int N, inputSize, counterSize;
	int year = 0;

	inputSize = sizeof(input);
	counterSize = sizeof(wordCounter);
	while (1) {
		scanf("%d", &N);
		if (N == 0)
			return 0;
		
		memset(input, 0x00, inputSize);
		memset(wordCounter, 0x00, counterSize);
		scanf("%s", wordSet);
		for (int i = 0; i < ENGNUM; ++i) {
			wordCounter[wordSet[i]-'A'] = i+1;
		}

		for (int i = 0; i < N; ++i) {
			scanf("%s", input[i].data);
			input[i].pWordCounter = wordCounter;
		}

		sort(input, input + N, comp);
		printf("year %d\n", ++year);
		for (int i = 0; i < N; ++i) {
			printf("%s\n", input[i].data);
		}
	}
	return 0;
}