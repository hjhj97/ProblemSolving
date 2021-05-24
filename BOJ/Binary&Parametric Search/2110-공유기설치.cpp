#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 212345
int arr[SIZE], gap[SIZE];
int n, max_dist;
int fCount(int space) {
	int start = arr[0];
	int ans = 1, mem = 0;

	for (int i = start; i + space <= max_dist; ) { //i는 현재 위치
		for (int j = mem; j < n; j++) {
			if (arr[j + 1] - i >= space) { //현재 집과 다음 집 사이의 간격이 space보다 넓으면 공유기 설치 가능
				ans++;
				i = arr[j + 1];
				mem = j + 1;
				break;
			}
		}

	}

	return ans;
}
int main() {
	int c;	scanf("%d %d", &n, &c);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);
	max_dist = arr[n - 1];

	int l = 1, r = max_dist, mid,ans;

	//upper bound search
	while (r >= l) {
		mid = (l + r) / 2;
		int cur = fCount(mid); //cur은 설치할 수 있는 공유기 최대 개수

		if (cur >= c) {
			ans = mid;
			l = mid + 1;
		}

		else r = mid - 1;

	}

	printf("%d\n", ans);

	return 0;
}
/*
5 3
1 2 8 4 9
->3

3 3
1 4 6
->2
*/
