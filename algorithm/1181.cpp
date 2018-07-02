#include <iostream>
#include <utility>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

set<pair<int, string>> p1;
string input[20000];

int main(int argc, char **argv)
{
	int N;
	
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> input[i];
		p1.insert(make_pair(input[i].length(), input[i]));
	}

	set<pair<int, string>>::iterator iter;
	for (iter = p1.begin(); iter != p1.end(); ++iter) {
		cout << (*iter).second << endl;
	}

	return 0;
}