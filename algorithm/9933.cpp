#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

	string s;
	vector<string> v, w;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> s;
		v.push_back(s);
		reverse(s.begin(), s.end());
		w.push_back(s);
	}

	for (auto vv : v) {
		for (auto ww : w) {
			if (!vv.compare(ww)) {
				cout << vv.size() << ' ' << vv.at(vv.size()/2) << endl;
				return 0;
			}
		}
	}


	return 0;
}