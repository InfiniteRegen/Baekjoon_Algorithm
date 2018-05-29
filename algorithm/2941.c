#include <stdio.h>
#include <string.h>

const char wordSet[8][4] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(int argc, char** argv)
{
	char input[101] = { 0 };
	int len, wordLen, count=0;
	int i, index = 0;

	scanf("%s", input);
	len = (int)strlen(input);
	count = len;

	while (index <= len) {

		for (i = 0; i < 8; ++i) {
			wordLen = strlen(wordSet[i]);
			if (strncmp(&input[index], wordSet[i], wordLen) == 0) {
				index += wordLen;
				count -= wordLen - 1;
				break;
			}
		}
		if (i == 8) index++;
	}

	printf("%d", count);

	return 0;
}