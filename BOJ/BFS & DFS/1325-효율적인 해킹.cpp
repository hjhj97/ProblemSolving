#include<stdio.h>
#include<queue>
#include<vector>
#define SIZE 10010
using namespace std;
int countNum[SIZE] = { 0 };
vector<int> v[SIZE];
int main() {
	int V, e;	scanf("%d %d", &V, &e);
	int maxNum = 0;

	for (int i = 0,a,b; i < e; i++) {
		scanf("%d %d", &a, &b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= V; i++) {
		queue<int> q;
		bool visited[SIZE] = { false };
		int Vcount = 0;
		q.push(i);	visited[i] = true;

		while (!q.empty()) {
			int cur = q.front();	 q.pop();

			for (int j = 0; j < v[cur].size(); j++) {
				int next = v[cur][j];

				if (!visited[next]) {
					q.push(next);
					visited[next] = true;
					Vcount++;
				}
			}
		}
		countNum[i] = Vcount;
		maxNum = (maxNum > Vcount) ? maxNum : Vcount;
	}
	for (int i = 1; i <= V; i++) {
		if (countNum[i] == maxNum)	printf("%d ", i);
	}
	return 0;
}
