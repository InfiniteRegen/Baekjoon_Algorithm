#include <stdio.h>

const char wordSet[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
const int daySet[12] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };

int main(int argc, char** argv)
{
	int mon = 0, day = 0;
	int daysGone = 0;

	scanf("%d %d", &mon, &day);

	for (int i = 0; i < mon; ++i) {
		daysGone += daySet[i];
	}
	daysGone += (day - 1);

	printf("%s", wordSet[daysGone % 7]);

	return 0;
}