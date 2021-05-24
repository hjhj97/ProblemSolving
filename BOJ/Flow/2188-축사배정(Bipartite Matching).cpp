#include<stdio.h>
#include<vector>
#define SIZE 211
using namespace std;
vector <int> v[SIZE];
int A[SIZE], B[SIZE];
bool visited[SIZE] = { false };
bool dfs(int a) {
	if (visited[a]) return false;
	visited[a] = true;
	for (int b : v[a]) {
		if (B[b] == -1 || dfs(B[b])) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}
int main() {
	int n, m;	scanf("%d %d", &n, &m);
	int ans = 0;

	for (int i = 0; i <= n; i++)
		A[i] = -1;
	for (int i = 0; i <= m; i++)
		B[i] = -1;

	for (int i = 1; i <= n; i++) {
		int a;	scanf("%d", &a);
		while (a--) {
			int b;	scanf("%d", &b);
			v[i].push_back(b);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			visited[j] = { false };
		if (dfs(i)) ans++;
	}
	printf("%d\n", ans);

	return 0;
}
