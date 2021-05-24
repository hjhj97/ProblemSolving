#include<stdio.h>
#define FAIL 10
int state[11][2] = {
{0,0},
{2,4}, //1
{FAIL,3}, //2
{2,4}, //3
{5,FAIL}, //4
{6,FAIL}, //5
{6,7}, //6
{2,8},//7
{9,8}, //8
{6,3}, //9
{FAIL,FAIL}//10
};
int main() {
	int t;	scanf("%d", &t);

	while (t--) {
		int cur = 1;
		char str[222];	scanf("%s", str);

		for (int i = 0; str[i]; i++) {
			cur = state[cur][str[i] - '0'];
		}

		bool ans = false;
		if (cur == 3 || cur == 7 || cur == 8)
			ans = true;

		printf("%s\n", (ans) ? "YES" : "NO");
	}
	return 0;
}
