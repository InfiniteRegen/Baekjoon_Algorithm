#include <stdio.h>
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(int argc, char** argv)
{
	int n, x;
	string k;
	deque <int> d;

	scanf("%d", &n);
	while (n--) {

		cin >> k;

		if (k == "push_front") {
			scanf("%d", &x);
			d.push_front(x);
		}
		else if (k == "push_back") {
			scanf("%d", &x);
			d.push_back(x);
		}
		else if (k == "pop_back") {
			if (!d.empty()) {
				printf("%d\n", d.back());
				d.pop_back();
			}
			else
				printf("-1\n");
		}
		else if (k == "pop_front") {
			if (!d.empty()) {
				printf("%d\n", d.front());
				d.pop_front();
			}
			else
				printf("-1\n");
		}
		else if (k == "size") {
			printf("%d\n", d.size());
		}
		else if (k == "empty") {
			printf("%d\n", d.empty());
		}
		else if (k == "front") {
			if (!d.empty())
				printf("%d\n", d.front());
			else
				printf("-1\n");
		}
		else if (k == "back") {
			if (!d.empty())
				printf("%d\n", d.back());
			else
				printf("-1\n");
		}
	}

	return 0;
}