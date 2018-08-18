#include <stdio.h>
#include <string.h>

char input[1001] = { 0, };

int main()
{
	int size = 0;
	scanf("%s", input);
	size = (int)strlen(input);
	
	for (int i = 0; i < size; ++i) {
		input[i] -= 3;
		if (input[i] < 'A')
			input[i] += 26;
	}
	printf("%s\n", input);
	return 0;
}