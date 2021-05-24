#include<stdio.h>
int n, m,ans=0;
int arr[111];
void dfs(int cnt,int last,int sum) {
	if (cnt == 3) {
		if (sum <= m && sum > ans)
			ans = sum;
		return;
	}
	for (int i = last + 1; i < n; i++) {
		dfs(cnt + 1, i, sum+arr[i]);
	}
	return;
}
int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(0, -1, 0);
	printf("%d\n", ans);
	return 0;
}
