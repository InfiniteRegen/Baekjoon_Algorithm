#include <stdio.h>
#include <string.h>

int counts[26];

int main(int argc, char** argv)
{
	int N;
	char input[101];
	int len;
	int gWordCount;

	scanf("%d", &N);
	gWordCount = N;
	for (int i = 0; i < N; ++i){
		scanf("%s", input);
		memset(counts, -1, sizeof(counts));
		len = (int)strlen(input);
		for (int j = 0; j < len; ++j) {
			if (counts[input[j] - 'a'] == 1) {
				gWordCount--;
				break;
			}else if (input[j] != input[j + 1]) {
				counts[input[j] - 'a'] = 1;
			}
		}
	}
	printf("%d", gWordCount);


	return 0;
}