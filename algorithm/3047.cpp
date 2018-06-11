#include <stdio.h>
#include <algorithm>

using namespace std;

int val[3] = { 0, };
char input[4] = { 0, };
int main(int argc, char** argv)
{
	for (int i = 0; i < 3; ++i)
		scanf("%d", &val[i]);

	scanf("%s", input);

	sort(val, val + 3);
	printf("%d %d %d", val[input[0] - 'A'], val[input[1] - 'A'], val[input[2] - 'A']);
	return 0;
}