#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
/*
	속도비교

	set <<<<< vector + sort
	vector로 sort시키는게 set으로 insertion하면서 정렬하는 것 보다 훨씬 빠르다
*/
int main(int argc, char** argv)
{
	int N, M;
	string s;
	vector<string> v, res;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < M; ++i) {
		cin >> s;
		if (binary_search(v.begin(), v.end(), s)) {
			res.push_back(s);
		}
	}

	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < (int)res.size(); ++i) {
		cout << res[i] << endl;
	}
	
	return 0;
}