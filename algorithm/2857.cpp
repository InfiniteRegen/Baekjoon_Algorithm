#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string s;
	vector<int> v;
	for (int i = 0; i < 5; ++i) {
		cin >> s;
		if (s.find("FBI") != string::npos) {
			v.push_back(i + 1);
		}
	}
	sort(v.begin(), v.end());

	if (v.empty()) {
		cout << "HE GOT AWAY!";
	}

	for (auto c : v) {
		cout << c << ' ';
	}

	return 0;
}