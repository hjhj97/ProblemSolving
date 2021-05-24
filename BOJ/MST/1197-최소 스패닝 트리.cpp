#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int p[11111];

int find(int a) {
	if (p[a] == -1)
		return a;

	p[a] = find(p[a]);
	return find(p[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}
struct s {
	int start, end, cost;

	const bool operator <(const s&a)const {
		return cost < a.cost;
	}
};
s tree[111111];

int main() {
	int v, e;	scanf("%d %d", &v, &e);
	int count = 0,cost_sum=0;

	for (int i = 0; i <= v; i++)
		p[i] = -1;

	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &tree[i].start, &tree[i].end, &tree[i].cost);
	}
	sort(tree, tree + e);

	for (int i = 0; (v-1)!=count ; i++) {
		if (find(tree[i].start) != find(tree[i].end)) { //서로 다른 트리에 속해있다면 ->두 노드 연결하고 count증가
			merge(tree[i].start, tree[i].end);
			cost_sum += tree[i].cost;
			count++;
		}
	}
	printf("%d\n", cost_sum);

	return 0;
}
