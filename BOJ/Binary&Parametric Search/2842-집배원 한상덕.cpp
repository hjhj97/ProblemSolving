#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#define SIZE 60
using namespace std;
struct Pos {
	int y, x;

	Pos() {}
	Pos(int _y, int _x) {
		y = _y;
		x = _x;
	}
};
vector<int> v;
char map[SIZE][SIZE];
int h[SIZE][SIZE];
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
int start_y, start_x, countK = 0, minNum = (int)2e+6, maxNum = -1, n;
int fMin(int a, int b) {
	return a > b ? b : a;
}
int fMax(int a, int b) {
	return a > b ? a : b;
}
bool bfs(int low, int high) {
	queue<Pos> q;
	bool visited[SIZE][SIZE] = { false };

	if (h[start_y][start_x] >= low && h[start_y][start_x] <= high) {
		q.push(Pos(start_y, start_x));
		visited[start_y][start_x] = true;
	}

	int cnt = 0;
	while (!q.empty()) {
		Pos cur = q.front();	q.pop();
		if (map[cur.y][cur.x] == 'K')	cnt++;

		for (int i = 0; i < 8; i++) {
			int nexti = cur.y + dy[i];
			int nextj = cur.x + dx[i];

			if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= n)	continue;
			if (h[nexti][nextj] >= low && h[nexti][nextj] <= high && !visited[nexti][nextj]) {
				q.push(Pos(nexti, nextj));
				visited[nexti][nextj] = true;
			}
		}
	}
	if (countK == cnt)	return true;
	else return false;
}
int main() {
	scanf("%d ", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n + 1; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'P') {
				start_y = i;	start_x = j;
			}
			else if (map[i][j] == 'K')
				countK++;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &h[i][j]);
			minNum = fMin(minNum, h[i][j]);
			maxNum = fMax(maxNum, h[i][j]);
			v.push_back(h[i][j]);
		}

	sort(v.begin(), v.end());
	int l_idx = 0, r_idx = 0, gap = (int)1e+6;

	while (1) {
		int l = v[l_idx], r = v[r_idx];
		if (bfs(l, r) == true) {
			l_idx++;
			gap = fMin(gap, r - l);
		}
		else r_idx++;

		if (r_idx < l_idx)	break;
		if (r_idx == n*n)	break;
	}

	printf("%d\n", gap);
	return 0;
}
