#include<stdio.h>
#include<math.h>
#define SIZE 1000010*8
typedef long long ll;
int start_i, tree_size;
ll tree[SIZE];
ll make_tree(int cur_node) {
	if (cur_node >= start_i)
		return tree[cur_node];

	tree[cur_node] = make_tree(cur_node * 2) + make_tree(cur_node * 2 + 1);

	return tree[cur_node];
}
ll sum(int cur_node,int ql,int qr,int cl,int cr) {
	if (cr<ql || cl>qr)
		return 0;

	if (cl>=ql && cr<=qr)
		return tree[cur_node];

	int mid = (cl + cr) / 2;

	return sum(cur_node * 2, ql, qr, cl, mid) + sum(cur_node * 2+1, ql, qr, mid + 1, cr);
}
void update(int change_node,int change_val) {
	tree[change_node] = change_val;
	int par = change_node / 2;

	while (par>=1) {
		tree[par] = tree[par * 2] + tree[par * 2 + 1];
		par /= 2;
	}
	return;
}
int main() {
	int n, m, k;	scanf("%d %d %d", &n, &m, &k);

	for (start_i = 1; start_i < n; start_i *= 2);
	tree_size = start_i * 2;

	for (int i = start_i; i < start_i + n; i++)
		scanf("%lld", &tree[i]);

	make_tree(1);

	for (int i = 0; i < m + k; i++) {
		int a, b, c;	scanf("%d %d %d", &a, &b, &c);

		if (a == 1) { //b번째 수를 c로 바꿈
			update(start_i+b-1, c);
		}
		else if (a == 2) { //b번째 부터 c번째 수의 합을 출력
			printf("%lld\n", sum(1,b, c,1,start_i));
		}
	}
	return 0;
}
