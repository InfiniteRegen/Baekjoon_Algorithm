#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

char input[5001] = { 0, };
int wordSet[26][2] = { 
	{ 0, 'a' },	{ 0, 'b' },	{ 0, 'c' },	{ 0, 'd' },	{ 0, 'e' },
	{ 0, 'f' },	{ 0, 'g' },	{ 0, 'h' },	{ 0, 'i' },	{ 0, 'j' },
	{ 0, 'k' },	{ 0, 'l' },	{ 0, 'm' },	{ 0, 'n' },	{ 0, 'o' },
	{ 0, 'p' },	{ 0, 'q' },	{ 0, 'r' },	{ 0, 's' },	{ 0, 't' },
	{ 0, 'u' },	{ 0, 'v' },	{ 0, 'w' },	{ 0, 'x' },	{ 0, 'y' },
	{ 0, 'z' },
};

int main()
{
	int len = 0;
	vector<pair<int ,char>> v;
	vector<char> w;

	while (scanf("%s", input) != EOF) {
		len = (int)strlen(input);
		for (int i = 0; i < len; ++i) {
			if (input[i] == ' ')
				continue;
			else if (input[i] == '\n') {
				continue;
			}
			else {
				wordSet[input[i] - 'a'][0]++;
			}
		}
	}
	
	for (int i = 0; i < 26; ++i)
		v.push_back({ wordSet[i][0], wordSet[i][1] });

	sort(v.begin(), v.end());
	w.push_back(v[25].second);
	for (int i = 25; i > 0; --i) {
		if (v[i].first != v[i - 1].first)
			break;
		w.push_back(v[i - 1].second);
	}

	sort(w.begin(), w.end());
	for (int i = 0; i < w.size(); ++i) {
		printf("%c", w[i]);
	}
	
	return 0;
}