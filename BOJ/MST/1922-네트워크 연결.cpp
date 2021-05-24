#include<stdio.h>
#include<algorithm>
#define V_SIZE 1010
#define E_SIZE 100100
using namespace std;
struct Edge {
	int from,to, cost;

	const bool operator <(const Edge &o) const {
		return cost < o.cost;
	}

	Edge(){}
	Edge(int from,int to, int cost) :from(from),to(to), cost(cost) {};
};
Edge edge[E_SIZE];
int p[V_SIZE];
int find(int a) {
	if (p[a] == -1) //자신이 루트이면
		return a;

	p[a] = find(p[a]);
	return find(p[a]);
}
void merge(int a, int b) {
	a = find(a);	b = find(b);
	if (a == b)	return;
	p[b] = a;
	return;
}
int main() {
	int V, e,min_cost=0;	scanf("%d %d", &V, &e);

	for (int i = 1; i <= V; i++)
		p[i] = -1;

	for (int i = 0,a,b,c ; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge[i]=Edge(a, b, c);
	}
	sort(edge, edge + e);

	for (int i = 0,connected=0; connected != V-1; i++) {
		if (find(edge[i].from) == find(edge[i].to))	continue;

		merge(edge[i].from, edge[i].to);
		min_cost += (edge[i].cost);
		connected++;
		}
	printf("%d\n", min_cost);

	return 0;
}
