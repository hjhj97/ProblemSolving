#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
#define SIZE 101
vector<int> g[SIZE];
vector<pair<int, int>> v[SIZE];
int inD[SIZE] = { 0 };
pair<int, int> pii[SIZE];
int main() {
	int n;	scanf("%d", &n);
	int max_order = 0;

	for (int i = 1; i <= n; i++) {
		int a, b;	scanf("%d %d", &a, &b);

		v[a].push_back(make_pair(i, b));
		max_order = max(max_order, a);
		pii[i] = make_pair(a, b);

	}
	for (int i = 1; i <= max_order - 1; i++) {
		for (auto there : v[i]) {
			int cur = there.first;

			for (auto nx : v[i + 1]) {
				int next = nx.first;
				g[cur].push_back(next);
				inD[next]++;
			}
		}
	}

	int max_time[SIZE] = { 0 };
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (inD[i] == 0) {
			q.push(i);
			max_time[i] = pii[i].second;
		}
	}

	while (!q.empty()) {
		int cur = q.front();	q.pop();

		for (int next : g[cur]) {
			max_time[next] = max(max_time[next], max_time[cur] + (int)pow(cur - next, 2));

			if (--inD[next] == 0) {
				q.push(next);
				max_time[next] += pii[next].second;
			}
		}
	}

	int ans = 0;

	for (auto nx : v[max_order]) {
		ans = max(ans, max_time[nx.first]);
	}

	printf("%d\n", ans);

	return 0;

}
