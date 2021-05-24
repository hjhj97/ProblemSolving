#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
#define SIZE 111
typedef pair<int, int> Cord;
vector<int> v[SIZE * SIZE*2];
map<int, int> cap[SIZE*SIZE * 2];
bool impossible = false;
int R, C,RC, ans = 0;
int dy[4] = { 1,-1,0,0 }, dx[4] = { 0,0,1,-1 }, pre[SIZE * SIZE*2];
char m[SIZE][SIZE];
int main() {
	scanf("%d %d ", &R, &C);
	int st_y, st_x, end_y, end_x;
	RC = R*C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C + 1; j++) {
			scanf("%c", &m[i][j]);
			if (m[i][j] == 'K') {
				st_y = i;
				st_x = j;
			}
			else if (m[i][j] == 'H') {
				end_y = i;
				end_x = j;
			}
		}
	}
	queue<Cord> q;

	for (int i = 0; i < 4; i++) {
		int next_i = st_y + dy[i];
		int next_j = st_x + dx[i];

		if (next_i < 0 || next_j < 0 || next_i >= R || next_j >= C)	continue;
		if (m[next_i][next_j] == 'H')
			impossible = true;
	}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			v[i*C+j].push_back(i*C+j + RC);

			cap[i*C+j][i*C+j + RC] = 1;
		}


	q.push(make_pair(st_y, st_x));
	bool visited[SIZE*2][SIZE*2] = { false };

	while (!q.empty()) {
		int cur_i = q.front().first, cur_j = q.front().second;
		visited[cur_i][cur_j] = true;
		int cur = cur_i*C + cur_j;
		int _cur = cur + RC;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + dy[i];
			int next_j = cur_j + dx[i];
			int next = next_i*C + next_j;
			int _next = next + RC;

			if (next_i < 0 || next_j < 0 || next_i >= R || next_j >= C)	continue;
			if (m[next_i][next_j] == '#') continue;

			v[_cur].push_back(next);
			cap[_cur][next] = 1;
			v[next].push_back(_cur);
			v[_next].push_back(cur);
			cap[_next][cur] = 1;

			if (visited[next_i][next_j])	continue;
			if (m[next_i][next_j] == 'H') continue;

			q.push(make_pair(next_i, next_j));
			visited[next_i][next_j] = true;
		}
	}
	int _S = st_y*C + st_x + RC;
	int T = end_y*C + end_x;
	while (1) {
		for (int i = 0; i <= 2 * RC; i++) {
			pre[i] = -1;
		}

		queue<int> q;
		q.push(_S);

		while (!q.empty()) {
			int cur = q.front();	q.pop();

			for (int next : v[cur]) {
				if (pre[next] != -1)	continue;
				if (cap[cur][next] > 0) {
					q.push(next);
					pre[next] = cur;
					if (next == T)
						break;
				}
			}
		}

		if (pre[T] == -1) break;

		for (int cur_pos = T; cur_pos != _S; cur_pos = pre[cur_pos]) {
			int pre_visit = pre[cur_pos];

			cap[pre_visit][cur_pos]--;
			cap[cur_pos][pre_visit]++;
		}
		ans++;
	}

	printf("%d\n", (impossible)?-1:ans);

	return 0;
}
/*
4 5
.....
....H
K....
.....
->3
*/
