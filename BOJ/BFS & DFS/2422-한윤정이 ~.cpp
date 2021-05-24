#include<stdio.h>
bool check[222][222] = { false };
long long ans = 0;
int n, m, pick[3];
void dfs(int cnt,int last) {
	if (cnt == 3) {
		ans++;
		return;
	}

	for (int i = last + 1; i <= n; i++) {
		if (check[last][i]) continue;
		if (cnt == 2) {
			if (check[pick[0]][i])	continue;
		}
		pick[cnt] = i;
		dfs(cnt + 1, i);
	}

	return;
}
int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;	scanf("%d %d", &a, &b);

		check[b][a] = true;
		check[a][b] = true;
	}
	for (int i = 1; i <= n; i++) {
		pick[0] = i;
		dfs(1, i);
	}

	printf("%lld\n", ans);
	return 0;
}
