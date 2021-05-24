#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int main() {
	vector<int> v[1111];
	queue<int> q;

	int buffer[1111] = { 0 },idx=0;
	int n, m, in[1111] = { 0 };	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int arr[1111] = { 0 };
		int k;	scanf("%d", &k);
		for (int j = 0; j < k; j++)
			scanf("%d", &arr[j]);

		for (int j = 0; j < k - 1; j++) {
			v[arr[j]].push_back(arr[j + 1]);
			in[arr[j + 1]]++;
		}
	}
	for (int i = 1; i <= n; i++)
		if (in[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int cur = q.front();
		buffer[idx++] = cur;
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			if (--in[v[cur][i]] == 0)
				q.push(v[cur][i]);
		}
		if (q.empty()&&idx!=n) {
			printf("0");
			return 0;
		}

	}
	for (int i = 0; i < n; i++)
		printf("%d ", buffer[i]);

	return 0;
}
