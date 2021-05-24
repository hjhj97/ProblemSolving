#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 500000
int start_i, tree_size;
int tree[SIZE * 8], lazy[SIZE * 8];
int make_SegTree(int cur_node) {
	if (cur_node >= start_i)	return tree[cur_node];

	return tree[cur_node] =
		make_SegTree(cur_node * 2) ^ make_SegTree(cur_node * 2 + 1);
}
void propagate(int cur_node, int cl, int cr) {
	if (lazy[cur_node]) {
		if (cur_node < start_i) {
			lazy[cur_node * 2] ^= lazy[cur_node];
			lazy[cur_node * 2 + 1] ^= lazy[cur_node];
		}
		else tree[cur_node] ^= lazy[cur_node]; //리프노드이면
		lazy[cur_node] = 0;
	}
	return;
}
void update(int cur_node, int ql, int qr, int cl, int cr, int num) {
	propagate(cur_node, cl, cr);

	if (qr<cl || ql>cr)	return;
	if (qr >= cr && ql <= cl) {
		if (cur_node < start_i) {
			lazy[cur_node * 2] ^= num;
			lazy[cur_node * 2 + 1] ^= num;
		}
		else tree[cur_node] ^= num;
		return;
	}
	int mid = (cl + cr) / 2;
	update(cur_node * 2, ql, qr, cl, mid, num);
	update(cur_node * 2 + 1, ql, qr, mid + 1, cr, num);
	tree[cur_node] = tree[cur_node * 2] ^ tree[cur_node * 2 + 1];
}
int GetXor(int cur_node, int ql, int qr, int cl, int cr) {
	propagate(cur_node, cl, cr);
	if (qr<cl || ql>cr)	return 0;
	if (qr >= cr && ql <= cl)	return tree[cur_node];

	int mid = (cl + cr) / 2;
	return GetXor(cur_node * 2, ql, qr, cl, mid) ^ GetXor(cur_node * 2 + 1, ql, qr, mid + 1, cr);

}
int main() {
	int n;	scanf("%d", &n);
	for (start_i = 1; start_i < n; start_i *= 2);
	tree_size = start_i * 2;

	for (int i = 0; i < n; i++)
		scanf("%d", &tree[start_i + i]);

	make_SegTree(1);

	int m;	scanf("%d", &m);
	while (m--) {
		int a, b, c;	scanf("%d %d %d", &a, &b, &c);
		if (b > c)	swap(b, c);

		if (a == 1) { //b부터 c까지 d를 xor 연산
			int d;	scanf("%d", &d);
			update(1, b + 1, c + 1, 1, start_i, d);
		}
		else { //b부터 c까지 xor연산 값 출력
			printf("%d\n", GetXor(1, b + 1, c + 1, 1, start_i));
		}
	}
	return 0;
}
