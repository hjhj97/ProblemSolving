#include<stdio.h>
#include<vector>
using namespace std;
#define SIZE 111
struct Brick {
	int a, h, w;

	Brick() {}
	Brick(int _a, int _h, int _w) {
		a = _a;
		h = _h;
		w = _w;
	}
};
int n, ans = 0, dp[SIZE];
Brick b[SIZE];
vector<int> v;
int fMax(int a, int b) {
	return a > b ? a : b;
}
int dfs(int cur) {
	if (dp[cur] != -1)	return dp[cur];

	int M = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i].a > b[cur].a && b[i].w > b[cur].w) {
			M = fMax(M, dfs(i));
		}
	}
	return dp[cur] = M + b[cur].h;
}
int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int aa, bb, cc;	 scanf("%d %d %d", &aa, &bb, &cc);
		b[i] = Brick(aa, bb, cc);
		dp[i] = -1;
	}

	int M = 0;
	for (int i = 1; i <= n; i++)
		M = fMax(M, dfs(i));

	Brick last = Brick(-1, -1, -1);
	for (int i = M; i > 0; ) {
		for (int j = 1; j <= n; j++) {
			if (dp[j] == i && (last.a < b[j].a && last.w < b[j].w)) {
				v.push_back(j);
				ans++;
				i -= b[j].h;
				last = b[j];
				break;
			}
		}
	}

	printf("%d\n", ans);
	for (int i : v)
		printf("%d\n", i);
	return 0;
}
