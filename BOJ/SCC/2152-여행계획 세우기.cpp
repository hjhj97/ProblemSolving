#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
#define SIZE 10000
#define IMP -10001
struct Edge {

};
vector<int> v[SIZE + 10];
vector<int> scc[SIZE + 10];
vector<int> scc_adj[SIZE + 10];
stack<int> s;
int st, e;
int low[SIZE + 10], idx[SIZE + 10], scc_idx[SIZE + 10], city_count[SIZE + 10];
int dp[SIZE + 10];
bool visited[SIZE + 10] = { false }, check = false, e_visited[SIZE + 10] = { false };
int cnt = 1, scc_cnt = 0;
int fMin(int a, int b) {
	return a > b ? b : a;
}
int fMax(int a, int b) {
	return a > b ? a : b;
}
void dfs(int cur) {
	low[cur] = idx[cur] = cnt++;
	s.push(cur);
	visited[cur] = true;

	for (int next : v[cur]) {
		if (idx[next] == 0) {
			dfs(next);
			low[cur] = fMin(low[cur], low[next]);
		}
		else if (visited[next])
			low[cur] = fMin(low[cur], low[next]);
	}

	if (low[cur] == idx[cur]) {
		while (1) {
			int top = s.top();	s.pop();
			visited[top] = false;
			scc[scc_cnt].push_back(top);
			scc_idx[top] = scc_cnt;
			city_count[scc_cnt]++;

			if (low[top] == idx[top])
				break;
		}
		scc_cnt++;
	}
}
int route_dfs(int cur) {
	if (cur == e) {
		e_visited[cur] = true;
		return dp[cur]=city_count[e];
	}
	if (dp[cur] != 0)
		if (e_visited[cur])	return dp[cur];
		else return IMP;

		for (int next : scc_adj[cur]) {
			dp[cur] = fMax(dp[cur], city_count[cur] + route_dfs(next));
			if (e_visited[next])	e_visited[cur] = true;
		}
		if (e_visited[cur])	return dp[cur];
		else return IMP;
}
int main() {
	int V, E;	scanf("%d %d %d %d", &V, &E, &st, &e);

	for (int i = 0, a, b; i < E; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
	}

	for (int i = 1; i <= V; i++)
		if (idx[i] == 0)	dfs(i);

	for (int i = 1; i <= V; i++)
		for (int j : v[i]) {
			if (scc_idx[i] == scc_idx[j])	continue;
			scc_adj[scc_idx[i]].push_back(scc_idx[j]);
		}

	st = scc_idx[st];	e = scc_idx[e];
	dp[st] = route_dfs(st);

	printf("%d\n", (dp[st]<=0)?0:dp[st]);
	return 0;

}
/*
6 6 1 6
1 2
2 3
3 4
4 5
5 2
5 6
->6
3 4 1 1
1 2
2 3
3 2
2 1
->3
5 5 1 5
1 2
2 3
3 4
4 2
5 4
->0
7 9 1 7
1 2
2 3
3 2
3 7
1 4
4 5
5 6
6 4
5 7
->5
5 5 1 4
1 2
2 3
3 4
3 5
5 2
->5
7 7 1 7
3 2
2 1
1 4
4 6
1 5
5 7
6 7
->4
5 3 2 5
1 2
2 3
3 5
4 5
->3
7 7 2 5
1 2
2 6
6 7
7 5
2 3
3 5
4 3
->4
5 6 1 1
1 2
2 3
3 1
1 4
4 5
5 1
->5
4 3 1 2
1 2
1 3
3 4
->2
*/
