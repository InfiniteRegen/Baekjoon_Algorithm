#include <stdio.h>
#include <algorithm>

using namespace std;

int input[9] = {0, };

int main(int argc, char** argv)
{
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &input[i]);
	}

	sort(input, input + 9);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 && j != i; j++) {
			sum = 0;
			
			for (int k = 0; k < 9; k++) {
				if (k != i && k != j) {
					sum += input[k];
				}
			}

			if (sum == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						printf("%d\n", input[k]);
					}
				}
			}

		}
	}

	return 0;
}