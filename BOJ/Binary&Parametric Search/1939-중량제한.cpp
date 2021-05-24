#include<stdio.h>
#include<vector>
#include<queue>
#define SIZE 100100
using namespace std;
struct Edge {
	int to, w;
	Edge() {}
	Edge(int to, int w) :to(to), w(w) {};
};
vector<Edge>v[SIZE];
queue<Edge>q;
int i1, i2;
bool Bfs(int base) {
	bool check[SIZE] = { false };
	while (!q.empty()) {
		Edge cur = q.front();	q.pop();
		if (cur.to == i2)
			return true;

		for (int i = 0; i < v[cur.to].size(); i++) {
			if (base <= v[cur.to][i].w) //다리를 건널 수 있다면
				if (check[v[cur.to][i].to] == false) {
					q.push(Edge(v[cur.to][i].to, base));
				}
		}
		check[cur.to] = true;
	}
	return false;
}
int main() {
	int n, m, max = 0;	scanf("%d %d", &n, &m);  //max는 최대 무게제한

	while (m--) {
		int a, b, c;	scanf("%d %d %d", &a, &b, &c);
		max = (c > max) ? c : max;
		v[a].push_back(Edge(b, c));	v[b].push_back(Edge(a, c));
	}
	scanf("%d %d", &i1, &i2);

	int l = 1, r = max, mid,ans;

	//upper bound search
	while (r >= l) {
		while (!q.empty()) {
			q.pop();
		}
		mid = (r + l) / 2; //mid의 무게로 i1~i2로 운반이 가능한지 시험.
		q.push(Edge(i1, mid));

		if (Bfs(mid)) { //i2에 도달했다면 무게를 조금 증가시켜서 다시 시험.
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	printf("%d\n", ans);

	return 0;
}
