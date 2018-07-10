#include <stdio.h>
#include <deque>

using namespace std;

int main(int argc, char** argv)
{
	int N, M;
	int current, index, counter = 0;
	int left, right;
	int size = 0;
	deque<int> d;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i) {
		d.push_back(i);
	}

	for (int i = 0; i < M; ++i) {
		scanf("%d", &current);
		index = 1;
		size = d.size();

		for (deque<int>::iterator iter = d.begin(); iter != d.end(); ++iter) {
			if (current == *iter)
				break;
			++index;
		}
			
		left = index - 1;
		right = size - index + 1;

		if (right > left) {
			for (int j = 1; j <= left; ++j) {
				d.push_back(d.at(0));
				d.pop_front();
				++counter;
			}
			d.pop_front();
		}
		else {
			for (int j = 1; j <= right; ++j) {
				d.push_front(d.at(size - 1));
				d.pop_back();
				++counter;
			}
			d.pop_front();
		}
	}

	printf("%d", counter);

	return 0;
}