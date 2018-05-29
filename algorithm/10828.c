#include <stdio.h>
#include <string.h>

int stack[10000];

int main(int argc, char** argv)
{
	int N;
	char command[10];
	int data;
	int idx = -1;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%s", command);
		if (!strcmp(command, "push")) {
			scanf("%d", &data);
			stack[++idx] = data;
		}
		else if (!strcmp(command, "pop")) {
			if (idx < 0) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", stack[idx]);
			stack[idx--] = 0;
		}
		else if (!strcmp(command, "size")) {
			printf("%d\n", idx + 1);
		}
		else if (!strcmp(command, "empty")) {
			if (idx < 0) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (!strcmp(command, "top")) {
			if (idx < 0) {
				printf("1\n");
			}
			else {
				printf("%d\n", stack[idx]);
			}
		}
	}

	return 0;
}