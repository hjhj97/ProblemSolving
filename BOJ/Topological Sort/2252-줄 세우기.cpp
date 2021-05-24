#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
queue<int> q;
vector<int> vec[33333];
int in_degree[33333];
bool check[33333] = { false };
int main() {
	int n, m;	scanf("%d %d", &n, &m);

	int u, v;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		vec[u].push_back(v);
		in_degree[v]++;
	}

	for (int i = 1; i <= n; i++)
		if (in_degree[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		printf("%d ", cur);
		for (int i = 0; i < vec[cur].size(); i++) {
			if (--in_degree[vec[cur][i]] == 0)
				q.push(vec[cur][i]);
		}
	}

	return 0;
}
