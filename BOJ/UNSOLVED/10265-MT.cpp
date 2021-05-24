#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#define SIZE 1000
using namespace std;
vector<int> v[SIZE+10];
stack<int> s;
int idx[SIZE + 10], low[SIZE + 10], scc_idx[SIZE + 10],scc_num[SIZE+10];
int total_count[SIZE + 10];
bool visited[SIZE + 10] = { false };
int cnt = 1, scc_cnt = 0;
int fMin(int a, int b) {
	return a > b ? b : a;
}
void Dfs(int cur) {
	idx[cur] = low[cur] = cnt++;
	s.push(cur);
	visited[cur] = true;

	for (int next : v[cur]) {
		if (idx[next] == 0) {
			Dfs(next);
			low[cur] = fMin(low[cur], low[next]);
		}
		else if (cur == next)
			scc_num[scc_cnt++] = 1;

		else if (visited[next])
			low[cur] = fMin(low[cur], low[next]);
	}
	if (low[cur] == idx[cur]) {
		while (1) {
			int top = s.top();	s.pop();
			visited[top] = false;
			scc_num[scc_cnt]++;
			scc_idx[top] = scc_cnt;

			if (low[top] == idx[top]) {
				if (scc_num[scc_cnt] == 1)
					scc_num[scc_cnt] = 0;

				break;
			}
		}
		scc_cnt++;
	}
}
int main() {
	int n, k,ans=0;	scanf("%d %d", &n, &k);

	for (int i = 1, a; i <= n; i++) {
		scanf("%d", &a);
		v[i].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		if (idx[i] == 0)	Dfs(i);

	sort(scc_num, scc_num + scc_cnt);

	for (int i = 0; i < scc_cnt; i++)
		printf("%d\n", scc_num[i]);

	for (int i = 0; i<scc_cnt; i++) {
		if (ans + scc_num[scc_cnt-i-1] <= k)
			ans += scc_num[scc_cnt-i-1];
	}
	//printf("%d\n", ans);
	return 0;
}
