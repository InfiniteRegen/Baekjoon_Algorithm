#include <iostream>
#include <string.h>
#include <functional>
#include <algorithm>

using namespace std;

char input[10];
int main(int argc, char** argv)
{

	cin >> input;

	sort(input, input + strlen(input), greater<int>());
	for (int i = 0; i < strlen(input); i++) {
		cout << input[i];
	}

	return 0;
}