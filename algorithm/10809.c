#include <stdio.h>
#include <string.h>

int counts[26];

/* 10809.c */
int main(int argc, char** argv)
{
	char input[101];
	int len = 0;

	scanf("%s", input);
	len = (int)strlen(input);

	memset(counts, -1, sizeof(counts));

	for (int i = 0; i < len; ++i) {
		if (counts[input[i] - 'a'] == -1)
			counts[input[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; ++i) {
		printf("%d ", counts[i]);
	}
	return 0;
}