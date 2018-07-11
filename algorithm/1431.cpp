#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	int N = 0;
	int sum = 0;
	string input;
	vector<pair<int, pair<int, string>>> v;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> input;
		for (auto c : input) {
			if (isdigit(c)) {
				sum += (c - '0');
			}
		}
		v.push_back(make_pair(input.size(), make_pair(sum, input)));
		sum = 0;
	}

	sort(v.begin(), v.end());

	for (vector<pair<int, pair<int, string>>>::iterator iter = v.begin(); iter != v.end(); ++iter) {
		cout << (*iter).second.second << endl;
	}

	return 0;
}