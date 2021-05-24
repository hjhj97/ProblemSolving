#include<stdio.h>
#include<vector>
#define SIZE 2010
using namespace std;
int A[SIZE], B[SIZE];
bool visited[SIZE];
int flag[SIZE][SIZE] = { 0 };
char str[SIZE][SIZE] = { 0 };
vector<int> v[SIZE];
bool dfs(int node) {
	visited[node] = true;

	for (int b : v[node]) {
		if (visited[B[b]]) continue;
		if (B[b] == 0 || !visited[B[b]] && dfs(B[b])) {
			A[node] = b;
			B[b] = node;
			return true;
		}
	}
	return false;
}
void clear() {
	for (int i = 0; i < SIZE; i++) {
		A[i] = 0;
		B[i] = 0;
		v[i].clear();
		for (int j = 0; j < SIZE; j++) {
			flag[i][j] = 0; str[i][j] = 0;
		}

	}
}
int main() {
	int t;	scanf("%d", &t);
	while (t--) {
		int h, V, ans = 0;	scanf("%d %d", &h, &V);

		for (int i = 0; i < h; i++) {
			char tmp[SIZE] = { 0 };
			int x, y;	scanf("%d %d %s", &x, &y, tmp);

			for (int j = 0; tmp[j]; j++) {
				str[y][x + j] = tmp[j];
				flag[y][x + j] = 1 + i;
			}
		}

		for (int i = 0; i < V; i++) {
			char tmp[SIZE] = { 0 };
			int x, y;	scanf("%d %d %s", &x, &y, tmp);

			for (int j = 0; tmp[j]; j++) {
				if (str[y + j][x] != 0) {
					if (str[y + j][x] == tmp[j])	continue;
					else {
						int num = flag[y + j][x];
						v[num].push_back(1 + h + i);
					}
				}
			}
		}

		for (int i = 1; i < SIZE; i++) {
			for (int j = 1; j < SIZE; j++)
				visited[j] = false;
			if (dfs(i)) ans++;
		}
		printf("%d\n", h + V - ans);
		clear();
	}

	return 0;
}
