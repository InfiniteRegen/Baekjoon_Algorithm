#include <stdio.h>
#include <string.h>

int counts[26] = { 0 };
/* 2675.c */
int main(int argc, char** argv)
{
	char input[1000001];
	int len = 0, max = 0;
	char res;

	scanf("%s", input);
	len = (int)strlen(input);
	if (len == 0) {
		printf("?");
		return 0;
	}

	for (int i = 0; i < len; ++i) {
		if (input[i] <= 'Z')
			counts[input[i] - 'A']++;
		else
			counts[input[i] - 'a']++;
	}

	max = counts[0];
	res = 'A';
	for (int i = 1; i < 26; ++i) {
		if (max < counts[i]) {
			max = counts[i];
			res = 'A' + i;
		}
		else if (max == counts[i]) {
			res = '?';
		}
	}

	printf("%c", res);

	return 0;
}