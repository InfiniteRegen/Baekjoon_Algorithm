#include <stdio.h>
#include <string.h>

int item[10] = { 0, };

int main(int argc, char** argv)
{
	char input[8] = { 0 };
	int count = 0;
	
	scanf("%s", input);
	memset(item, -1, sizeof(item));

	for (int i = 0; i < (int)strlen(input); ++i) {
		
		if (item[input[i] - '0'] == -1) {
			if (input[i] == '9' && item[6] != -1) {
				item[6]--;
				continue;
			}
			else if (input[i] == '6' && item[9] != -1) {
				item[9]--;
				continue;
			}
			else {
				count++;
				for (int j = 0; j < 10; ++j)
					item[j]++;
			}
		}
		item[input[i] - '0']--;
	}

	printf("%d\n", count);

	return 0;
}