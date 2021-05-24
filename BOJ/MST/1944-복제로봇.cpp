#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> p;
struct Edge {
	int from, to, cost;

	Edge(){}
	Edge(int _from,int _to,int _cost) {
		from = _from;
		to = _to;
		cost = _cost;
	}

	const bool operator<(const Edge &o) {
		return cost < o.cost;
	}
};
struct Find {
	int y, x, cost;

	Find(){}
	Find(int _y, int _x, int _cost) {
		y = _y;
		x = _x;
		cost = _cost;
	}
};
vector<Edge> v;
char map[55][55];
int n, m,par[333],idx=1,idx_arr[55][55];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int find(int a) {
	if (par[a] == -1)
		return a;
	return par[a] = find(par[a]);
}
void merge(int a,int b) {
	a = find(a);
	b = find(b);
	if (a == b)	return;
	par[b] = a;
}
int abs(int a) {
	return a > 0 ? a : -a;
}
int main() {
	scanf("%d %d ", &n, &m);
	vector<p> spot;
	for (int i = 0; i < 333; i++)
		par[i] = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'S' || map[i][j]== 'K') {
				spot.push_back(make_pair(i, j));
				idx_arr[i][j] = idx++;
			}
		}
	}
	int size = spot.size();
	for (int i = 0; i < size; i++) {
		int is_possible = 1;
		queue<Find> q;
		bool visited[333][333] = { false };
		visited[spot[i].first][spot[i].second] = true;
		q.push(Find(spot[i].first,spot[i].second,0));
		while (!q.empty()) {
			int cur_i = q.front().y;
			int cur_j = q.front().x;
			int cur_cost = q.front().cost;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nexti = cur_i + dy[j];
				int nextj = cur_j + dx[j];
				if (nexti < 0 || nextj < 0 || nexti >= n || nextj >= n)	continue;

				if (map[nexti][nextj]!='1' && !visited[nexti][nextj]) {
					if (map[nexti][nextj] == 'S' || map[nexti][nextj] == 'K') {
						is_possible++;
						if(idx_arr[nexti][nextj] > i+1)
							v.push_back(Edge(i+1, idx_arr[nexti][nextj], cur_cost + 1));
					}
					q.push(Find(nexti,nextj,cur_cost+1));
					visited[nexti][nextj] = true;
				}
			}
		}
		if (is_possible != m + 1) {
			printf("-1\n");
			return 0;
		}
	}

	sort(v.begin(), v.end());
	int connected = 0,ans=0;

	for (int i = 0; connected != size - 1; i++) {
		Edge cur = v[i];
		int from = cur.from;
		int to = cur.to;
		int cost = cur.cost;
		if (find(from) != find(to)) {
			merge(from, to);
			ans += cost;
			connected++;
		}
	}
	printf("%d\n", ans);

	return 0;
}
/*
4 1
1111
S111
001K
1111
->-1
*/
