#include <stdio.h>

int c[1001];
int main(int argc, char** argv)
{
	int n, m;
	int counter = 0, result = 0;

	scanf("%d %d", &n, &m);
	
	for (int i = 2; i <= n; ++i) {
		for (int j = i; j <= n; j += i) {
			if (c[j] == 0) { 
				counter++; 
				c[j] = 1;
			}
			
			if (counter == m) { 
				result = j; 
				break; 
			}
		}
		if (counter == m)
			break;
	}

	printf("%d\n", result);
	return 0;
}