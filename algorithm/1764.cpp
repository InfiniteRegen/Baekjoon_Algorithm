#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
/*
	�ӵ���

	set <<<<< vector + sort
	vector�� sort��Ű�°� set���� insertion�ϸ鼭 �����ϴ� �� ���� �ξ� ������
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