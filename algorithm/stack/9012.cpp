#include <stdio.h>
#include <stack>

using namespace std;

int main(int argc, char** argv)
{
	int N, len=0, j=0;
	char input[51];
	stack<char> ps;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		while (!ps.empty()) ps.pop();
		scanf("%s", input);
		len = (int)strlen(input);

		for (j = 0; j < len; ++j) {
			if (input[j] == '(') {
				ps.push('(');
			}
			else {
				if (ps.empty()) {
					printf("NO\n");
					break;
				}else if (ps.top() != '(') {
					printf("NO\n");
					break;
				}
				ps.pop();
			}
		}
		if (j == len) {
			if (ps.empty())
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}