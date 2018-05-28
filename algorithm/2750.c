#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	int N;
	int input[1000];

	cin >> N;

	for (int i = 0; i<N; ++i) {
		cin >> input[i];
	}

	sort(input, input + N);

	for (int i = 0; i < N; i++) {
		cout << input[i] << endl;
	}
	return 0;
}