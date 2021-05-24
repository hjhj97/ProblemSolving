#include<stdio.h>
#include<math.h>
#define SIZE 234567
#define TREESIZE 345678
#define INF 1<<30
long long tree[TREESIZE];
int start_i;
typedef long long ll;

ll fmin(ll a, ll b) {
	return a > b ? b : a;
}
ll make_tree(int cur_node) { //맨 처음에 트리 만듦
	if (cur_node >= start_i)
		return tree[cur_node];

	return tree[cur_node] = fmin(make_tree(cur_node * 2), make_tree(cur_node * 2 + 1));

}
void update(int i, int a) { //i번째 인덱스를 a로 바꿈
	tree[i] = a;
	int par = i / 2;
	while (par >= 1) {
		tree[par] = fmin(tree[par * 2], tree[par * 2 + 1]);
		par /= 2;
	}
	return;
}
ll find_min(int cur_node,int ql,int qr,int cl,int cr) { //qleft~qright 값 중에서 가장 작은 값 반환
	if (cl > qr || ql > cr) //범위가 완전히 벗어남
		return INF;
	if (cl>=ql && qr>=cr)//범위가 완전히 안에 들어옴
		return tree[cur_node];

	int mid = (cl + cr) / 2;

	return fmin(find_min(cur_node * 2, ql, qr, cl, mid), find_min(cur_node * 2 + 1, ql, qr, mid + 1, cr));

}
int main() {
	int n, tree_size;	scanf("%d", &n);

	int a = ceil(log2(n));
	start_i = 1 << a;
	tree_size = start_i * 2;

	for (int i = 1; i <= tree_size; i++)
		tree[i] = INF;

	for (int i = start_i ; i < start_i+n ; i++)
		scanf("%lld", &tree[i]);

	make_tree(1);

	int m;	scanf("%d", &m);
	while (m--) {
		int a;	scanf("%d", &a);

		if (a == 1) {
			int b, c;	scanf("%d %d", &b, &c);
			update(b + start_i - 1, c);
		}

		else if (a == 2) {
			int b, c;	scanf("%d %d", &b, &c);
			printf("%lld\n", find_min(1, b, c, 1, start_i));
		}
	}
	return 0;
}
