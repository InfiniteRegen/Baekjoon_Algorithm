#include <stdio.h>

#define SIZE 10

int top=0;
int s[SIZE];

void push(int d)
{
	if(top >= SIZE) {
        printf("overflow\n");
		return;
	}
	else {
		s[top] = d;
		top++;
	}
    return;
}

int pop()
{
	int ret = 0;

	if(top <= 0) {
		printf("empty\n");
		return -1;
    }
	else {
		ret = s[top-1];
		s[top-1]=0;
		top--;
	}
    return ret;
}

int peak()
{
	if(top <= 0) {
        printf("empty\n");
	    return -1;
    }
	else {
		return s[top-1];
	}

}

int main(int argc, char ** argv)
{

	push(1);
	push(2);
	printf("[1] %d \n", peak());
	push(3);
	printf("[2] %d \n", peak());

	printf("[3] %d \n", pop());
	printf("[4] %d \n", pop());
	printf("[5] %d \n", pop());
	printf("[6] %d \n", pop());

    return 0;
}
