#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
		return false;

	return false;
}

int main(int argc, char** argv)
{
	int N;
	vector<pair<int, string>> v;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;

	stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";

	return 0;
}