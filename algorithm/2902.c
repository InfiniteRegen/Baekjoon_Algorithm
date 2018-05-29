#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	char input[101] = { 0 };
	int len = 0;

	scanf("%s", input);
	len = (int)strlen(input);

	for (int i = 0; i < len; ++i) {
		if (input[i] - 'A' < 26 && input[i] - 'A' >= 0) {
			printf("%c", input[i]);
		}
	}

	return 0;
}