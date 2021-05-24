#include<stdio.h>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int main() {
	int n, m, in[33333] = { 0 };	scanf("%d %d", &n, &m);
	priority_queue<int,vector<int>,greater<int>> pq;
	vector<int> v[33333];

	for (int i = 0; i < m; i++) {
		int a, b;	scanf("%d %d", &a, &b);
		v[a].push_back(b);
		in[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)
			pq.push(i);
	}
		while (!pq.empty()) {
			int cur = pq.top();
			printf("%d ", cur);
			pq.pop();

			for (int i = 0; i < v[cur].size(); i++)
				if (--in[v[cur][i]] == 0)
					pq.push(v[cur][i]);
		}

	return 0;

}
