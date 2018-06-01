#include <stdio.h>
#include <queue>

int stack[100000];
int idx = -1;

using namespace std;

int peak()
{
	if (idx == -1) return -1;
	return stack[idx];
}

void push(int data)
{
	stack[++idx] = data;
	return;
}

int pop()
{
	if (idx == -1)
		return -1;
	stack[idx] = 0;
	return stack[idx--];
}

int main(int argc, char** argv)
{
	int N, input[100000];
	int seq = 0, data = 1;
	queue<char> result;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &input[i]);
	}

	while (1) {

		if (peak() == input[seq]) {
			pop();
			result.push('-');
			seq++;
			if (seq == N) {
				while (!result.empty()) {
					printf("%c\n", result.front());
					result.pop();
				}
				return 0;
			}
		}
		else if (data <= N) {
			push(data++);
			result.push('+');
		}
		else 
			break;
		
	}

	printf("NO\n");

	return 0;
}