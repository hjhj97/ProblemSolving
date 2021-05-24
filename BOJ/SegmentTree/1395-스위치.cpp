#include<stdio.h>
#define SIZE 100000
int start_i, tree_size;
int tree[SIZE * 8], lazy[SIZE * 8];
void propagate(int cur_node, int cl, int cr) {
	if (lazy[cur_node]) {
		tree[cur_node] = (cr - cl + 1) - tree[cur_node];
		if (cur_node < start_i) {
			lazy[cur_node * 2] = !lazy[cur_node*2];
			lazy[cur_node * 2 + 1] = !lazy[cur_node * 2 + 1];
		}
		lazy[cur_node] = 0;
	}
}
void toggle(int cur_node, int ql, int qr, int cl, int cr) {
	propagate(cur_node, cl, cr);

	if (qr<cl || ql>cr)	return;
	if (qr >= cr && cl >= ql) {
		tree[cur_node] = (cr - cl + 1) - tree[cur_node];
		if (cur_node < start_i) {
			lazy[cur_node * 2] = !lazy[cur_node * 2];
			lazy[cur_node * 2 + 1] = !lazy[cur_node * 2 + 1];
		}
		return;
	}

	int mid = (cl + cr) / 2;
	toggle(cur_node * 2, ql, qr, cl, mid);
	toggle(cur_node * 2 + 1, ql, qr, mid + 1, cr);
	tree[cur_node] = tree[cur_node * 2] + tree[cur_node * 2 + 1];
}
int GetSum(int cur_node, int ql, int qr, int cl, int cr) {
	propagate(cur_node, cl, cr);

	if (qr<cl || ql>cr)	return 0;
	if (qr >= cr && cl >= ql)
		return tree[cur_node];


	int mid = (cl + cr) / 2;
	return GetSum(cur_node * 2, ql, qr, cl, mid) + GetSum(cur_node * 2 + 1, ql, qr, mid + 1, cr);

}
int main() {
	int n, m;	scanf("%d %d", &n, &m);
	for (start_i = 1; start_i < n; start_i *= 2);
	tree_size = start_i * 2;
	while (m--) {
		int a, b, c;	scanf("%d %d %d", &a, &b, &c);
		if (a == 0) //b~c까지 스위치를 반전
			toggle(1, b, c, 1, start_i);
		else // b~c까지 켜져있는 스위치 개수 출력
			printf("%d\n", GetSum(1, b, c, 1, start_i));

	}

	return 0;
}
