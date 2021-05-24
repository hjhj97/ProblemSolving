#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
#define SIZE 111
int map[SIZE][SIZE];
int dy[4] = { 1,-1,0,0 }, dx[4] = { 0,0,1,-1 };
int fMin(int a, int b) {
	return a > b ? b : a;
}
int main() {
	int n, ans = 1 << 30;	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	int L = 0, R = 200, mid;

	//lower bound search
	while (R >= L) {
		mid = (L + R) / 2;
		bool flag = false;

		for (int i = 0; i + mid <= 200; i++) {
			int j = i + mid;

			queue<pair<int, int>> q;

			if (map[0][0] >= i && map[0][0] <= j)
				q.push(make_pair(0, 0));

			else continue;

			bool visited[SIZE][SIZE] = { false };
			visited[0][0] = true;

			while (!q.empty()) {
				int r = q.front().first;
				int c = q.front().second;
				q.pop();

				for (int k = 0; k < 4; k++) {
					int next_r = r + dy[k];
					int next_c = c + dx[k];

					if (visited[next_r][next_c]) continue;
					if (next_r < 0 || next_c < 0 || next_r >= n || next_c >= n) continue;
					if (map[next_r][next_c] >= i && map[next_r][next_c] <= j) {
						q.push(make_pair(next_r, next_c));
						visited[next_r][next_c] = true;
					}
				}
			}
			if (visited[n - 1][n - 1]) { //도달 가능
				R = mid - 1;
				ans = mid;
				flag = true;
				break;
			}
		}
		if(!flag) L = mid + 1;
	}

	printf("%d\n", ans);
	return 0;
}
