#include <stdio.h>
#include <string.h>

char input[150][31] = { 0, };
short wordCounter[26] = { 0, };

int main()
{
	int N;
	short flag = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", input[i]);
		wordCounter[input[i][0]-'a']++;
	}

	for (int i = 0; i < 26; ++i) {
		if (wordCounter[i] >= 5) {
			printf("%c", i + 'a');
			flag = 1;
		}
	}

	if (flag == 0)
		printf("PREDAJA");


	return 0;
}