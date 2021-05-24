#include<stdio.h>
#include<math.h>
#define SIZE 234567
#define TREESIZE 345678
#define INF 1<<30
#define SMALL -1
long long min_tree[TREESIZE];
long long max_tree[TREESIZE];
int start_i;
typedef long long ll;

ll fmin(ll a, ll b) {
	return a > b ? b : a;
}
ll fmax(ll a, ll b) {
	return a > b ? a : b;
}
ll make_max_tree(int cur_node) {
	if (cur_node >= start_i)
		return max_tree[cur_node];

	return max_tree[cur_node] = fmax(make_max_tree(cur_node * 2), make_max_tree(cur_node * 2 + 1));

}
ll make_min_tree(int cur_node) { //맨 처음에 트리 만듦
	if (cur_node >= start_i)
		return min_tree[cur_node];

	return min_tree[cur_node] = fmin(make_min_tree(cur_node * 2), make_min_tree(cur_node * 2 + 1));

}

ll find_min(int cur_node,int ql,int qr,int cl,int cr) { //qleft~qright 값 중에서 가장 작은 값 반환
	if (cl > qr || ql > cr) //범위가 완전히 벗어남
		return INF;
	if (cl>=ql && qr>=cr)//범위가 완전히 안에 들어옴
		return min_tree[cur_node];

	int mid = (cl + cr) / 2;

	return fmin(find_min(cur_node * 2, ql, qr, cl, mid), find_min(cur_node * 2 + 1, ql, qr, mid + 1, cr));

}
ll find_max(int cur_node, int ql, int qr, int cl, int cr) {
	if (cl > qr || ql > cr)
		return SMALL;
	if (cl >= ql && qr >= cr)
		return max_tree[cur_node];

	int mid = (cl + cr) / 2;

	return fmax(find_max(cur_node * 2, ql, qr, cl, mid), find_max(cur_node * 2 + 1, ql, qr, mid + 1, cr));

}
int main() {
	int n, m, tree_size;	scanf("%d %d", &n, &m);

	int a = ceil(log2(n));
	start_i = 1 << a;
	tree_size = start_i * 2;

	for (int i = 1; i <= tree_size; i++) {
		min_tree[i] = INF;
		max_tree[i] = SMALL;
	}

	for (int i = start_i; i < start_i + n; i++) {
		ll val;	scanf("%lld", &val);
		min_tree[i] = val;	max_tree[i] = val;
	}

	make_min_tree(1);	make_max_tree(1);

	while (m--) {
		int x, y;	scanf("%d %d", &x, &y);
		printf("%lld %lld\n", find_min(1, x, y, 1, start_i), find_max(1, x, y, 1, start_i));
	}


	return 0;
}
