#include<stdio.h>
#include<queue>
#include<vector>
#define SIZE 110
#define INF 1<<30
using namespace std;
struct Graph {
	int vx, count;

	Graph(){}
	Graph(int _vx, int _count) {
		vx = _vx;
		count = _count;
	};
};
vector<int> v[SIZE];
int result[SIZE];
int main() {
	int V, e;	scanf("%d %d", &V, &e);
	int min = INF,peopleNum=1;

	for (int i = 0, a, b; i < e; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);	v[b].push_back(a);
	}

	for (int i = 1; i <= V; i++) {
		int countTmp = 0;	int Count[SIZE];
		bool visited[SIZE] = { false };
		queue<Graph> q;
		q.push(Graph(i, 0));

		while (!q.empty()) {
			Graph cur = q.front();	q.pop();
			visited[cur.vx] = true;
			Count[cur.vx] = cur.count;
			countTmp = cur.count;

			for (int next : v[cur.vx]) {
				if (!visited[next])
					q.push(Graph(next, cur.count + 1));
			}
		}

		for (int j = 1; j <= V; j++)
			result[i] += Count[j];

		if (result[i] < min) {
			min=result[i];
			peopleNum = i;
		}

	}
	printf("%d\n", peopleNum);

	return 0;
}
