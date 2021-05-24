#include<stdio.h>
#define SIZE 100100
int time[SIZE];
int n;
int func(int cur) {
	int result = 1;

	for (int i = 0, sum = 0; i < n; ) {
		if (sum + time[i] <= cur) {
			sum += time[i++];

		}
		else {
			result++;
			sum = 0;
		}
	}
	return result;
}
int main() {
	int m,ans;	scanf("%d %d", &n, &m);
	int timeMax = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &time[i]);
		timeMax = (timeMax > time[i]) ? timeMax : time[i];
	}

	int l = timeMax, r = n * 11111, mid;

	//lower bound search
	while (r >= l) {
		mid = (l + r) / 2;
		int cur = func(mid);

		if (cur <= m) {
			ans = mid;
			r = mid - 1;
		}

		else
			l = mid + 1;

	}

	printf("%d\n", ans);

	return 0;
}
/*
4 4
1 2 3 4
->4

9 9
1 2 3 4 5 6 7 8 9
->9

9 3
1 2 3 4 5 6 7 8 9
->17

7 6
100
400
300
100
500
101
400
->500
*/
