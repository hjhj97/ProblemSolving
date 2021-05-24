//SCC by Kosaraju's Algorithm
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#define SIZE 10010
using namespace std;
vector<int> v[SIZE];
vector<int> rv[SIZE]; //역방향 간선
vector<int> scc[SIZE];
stack<int> s;
bool visited[SIZE] = { false };
int scc_cnt = 0;
void Dfs(int cur) {
	visited[cur] = true;

	for (int next : v[cur]) {
		if (!visited[next])	Dfs(next);
	}
	s.push(cur);

	return;
}
void RevDfs(int cur) {
	visited[cur] = true;
	scc[scc_cnt].push_back(cur);

	for (int next : rv[cur]) {
		if (!visited[next])	RevDfs(next);
	}
}
int main() {
	int V, e;	scanf("%d %d", &V, &e);

	for (int i = 0,a,b; i < e; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);	rv[b].push_back(a);
	}

	for (int i = 1; i <= V; i++) {
		if (!visited[i])	Dfs(i);
	}

	for (int i = 1; i <= V; i++)
		visited[i] = false;

	while (!s.empty()) {
		if (!visited[s.top()]) {
			RevDfs(s.top());
			scc_cnt++;
		}
		s.pop();
	}

	for (int i = 0; i < scc_cnt; i++) {
		sort(scc[i].begin(), scc[i].end());
	}
	sort(scc, scc + scc_cnt);


	printf("%d\n", scc_cnt);

	for (int i = 0; i < scc_cnt; i++) {
		for (int j = 0; j < scc[i].size(); j++)
			printf("%d ", scc[i][j]);
		printf("-1\n");
	}

	return 0;
}
/*
6 8
1 3
2 3
3 5
5 3
5 6
6 4
3 6
4 2

*/
