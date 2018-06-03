#include <stdio.h>
#include <string.h>

int queue[50000];
int front = -1;
int rear = 0;

void push(int data);
int pop();

int main(int argc, char** argv)
{
	int N = 0;
	char command[20];
	int data = 0;

	scanf("%d", &N);
	
	for (int i = 0; i < N; ++i) {
		scanf("%s", command);
		if (!strcmp(command, "push")) {
			scanf("%d", &data);
			push(data);
		}
		else if (!strcmp(command, "pop")) {
			data = pop();
			printf("%d\n", data);
		}
		else if (!strcmp(command, "size")) {
			printf("%d\n", front - rear + 1);
		}
		else if (!strcmp(command, "empty")) {
			if (front - rear + 1 == 0) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (!strcmp(command, "front")) {
			if (front - rear + 1 == 0) {
				printf("-1\n");
			}else 
				printf("%d\n", queue[rear]);
		}
		else if (!strcmp(command, "back")) {
			if (front - rear + 1 == 0) {
				printf("-1\n");
			}else
				printf("%d\n", queue[front]);
		}
	}
	
	return 0;
}

void push(int data)
{
	queue[++front] = data;
	return;
}

int pop()
{
	if (front < rear)
		return -1;
	return queue[rear++];
}