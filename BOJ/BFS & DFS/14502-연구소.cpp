#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define SIZE 8
typedef pair<int, int> Cord;
int map[SIZE][SIZE], map_origin[SIZE][SIZE],pick[3];
int n, m, ans = 0, mul;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
vector<Cord> init;
void copy_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map_origin[i][j] = map[i][j];
		}
	}
}
void bfs() {
	queue<Cord> q;

	for (auto here : init)
		q.push(here);

	copy_map();

	while (!q.empty()) {
		auto cur = q.front();	q.pop();

		for (int i = 0; i < 4; i++) {
			int nexti = cur.first + dy[i];
			int nextj = cur.second + dx[i];

			if (nexti < 0 || nextj < 0 || nexti >= n || nextj >= m) continue;
			if (map[nexti][nextj] == 0) {
				q.push(make_pair(nexti, nextj));
				map[nexti][nextj] = 2;
			}
		}
	}

	int safe = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) safe++;
		}
	}

	ans = max(ans, safe);
}
void return_back() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = map_origin[i][j];
		}
	}
	return;
}
void dfs(int cnt, int last) {
	if (cnt == 3) {
		bfs();
		return_back();
		return;
	}

	for (int i = last + 1; i < mul ; i++) {
		int r = i / m, c = i % m;
		if (map[r][c] == 0) {
			map[r][c] = 1;
			pick[cnt] = i;
			dfs(cnt + 1, i);
			map[r][c] = 0;
		}
	}

	return;
}
int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				init.push_back(make_pair(i, j));
			}
		}
	}

	mul = n*m;
	dfs(0,-1);
	printf("%d\n", ans);

	return 0;
}
