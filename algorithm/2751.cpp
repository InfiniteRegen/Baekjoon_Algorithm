#include <stdio.h>
#include <stdlib.h>

void merge(int* array, int start, int mid, int end)
{
	int* tmp = (int*) malloc(sizeof(int) * (end - start + 1));
	int tmp_index = 0;
	int p = start, q = mid + 1;
	int i;

	for (i = tmp_index; i <= end - start; i++) {
		while (p <= mid && q <= end) {
			if (array[p]>array[q]) {
				tmp[tmp_index] = array[q];
				q++;
			}
			else {
				tmp[tmp_index] = array[p];
				p++;
			}
			tmp_index++;
		}

		if (p>mid) {
			while (q <= end) {
				tmp[tmp_index] = array[q];
				q++;
				tmp_index++;
			}
		}
		else {
			while (p <= mid) {
				tmp[tmp_index] = array[p];
				p++;
				tmp_index++;
			}
		}
	}

	for (i = start; i <= end; i++) {
		array[i] = tmp[i - start];
	}

	free(tmp);
}

void merge_sort(int* array, int start, int end)
{
	if (start >= end)
		return;

	int mid = (start + end) / 2;

	merge_sort(array, start, mid);
	merge_sort(array, mid + 1, end);

	merge(array, start, mid, end);
}

int main(int argc, char** argv)
{
	int *ary;
	int N = 0, i;

	scanf("%d", &N);
	ary = (int *)malloc(sizeof(int)* N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &ary[i]);
	}

	merge_sort(ary, 0, N - 1);

	for (i = 0; i<N; i++){
		printf("%d\n", ary[i]);
	}

	free(ary);

	return 0;
}