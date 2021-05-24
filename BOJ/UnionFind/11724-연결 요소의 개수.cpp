#include<stdio.h>
#include<vector>
#define SIZE 1010
using namespace std;
vector<int> v[SIZE];
bool check[SIZE] = { false };
void Dfs(int cur) {
	check[cur] = true;

	for (int next : v[cur]) {
		if(!check[next])
			Dfs(next);
	}
	return;
}
int main() {
	int V, e;	scanf("%d %d", &V, &e);
	int ans = 0;

	for (int i = 0,a,b; i < e; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= V; i++)
		if (!check[i]) {
			ans++;
			Dfs(i);
		}

	printf("%d\n", ans);

	return 0;
}
