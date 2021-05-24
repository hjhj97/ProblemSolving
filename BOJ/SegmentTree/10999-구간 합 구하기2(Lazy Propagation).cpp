#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 1000000*8
typedef long long ll;
int n, m, k, tree_size, start_i;
ll tree[SIZE], lazy[SIZE];
void propagate(int cur_node, int cl, int cr) {
	if (lazy[cur_node] != 0) {
		tree[cur_node] += lazy[cur_node] * (cr - cl + 1);
		if (cur_node < start_i) {
			lazy[cur_node * 2] += lazy[cur_node];
			lazy[cur_node * 2 + 1] += lazy[cur_node];
		}
		lazy[cur_node] = 0;
	}
	return;
}

void update(int cur_node, int cl, int cr, int ql, int qr, int num) {
	propagate(cur_node, cl, cr);
	if (cl > qr || cr < ql) return;
	if (cl >= ql && cr <= qr) {
		lazy[cur_node] += num;
		propagate(cur_node, cl, cr);
		return;
	}

	int mid = (cl + cr) / 2;
	update(cur_node * 2, cl, mid, ql, qr, num);
	update(cur_node * 2 + 1, mid + 1, cr, ql, qr, num);

	tree[cur_node] = tree[cur_node * 2] + tree[cur_node * 2 + 1];
	return;
}

ll getSum(int cur_node, int cl, int cr, int ql, int qr) {
	propagate(cur_node, cl, cr);
	if (cl > qr || cr < ql) return 0;
	if (cl >= ql && cr <= qr) return tree[cur_node];

	int mid = (cl + cr) / 2;
	return getSum(cur_node * 2, cl, mid, ql, qr) + getSum(cur_node * 2 + 1, mid + 1, cr, ql, qr);
}

ll make_tree(int cur_node) {
	if (cur_node >= start_i) return tree[cur_node];
	return tree[cur_node] = make_tree(cur_node * 2) + make_tree(cur_node * 2 + 1);
}

int main() {
	scanf("%d %d %d", &n, &m, &k);

	for (start_i = 1; start_i < n; start_i *= 2);
	tree_size = start_i * 2;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &tree[i + start_i]);
	}

	make_tree(1);

	for (int i = 0; i < m + k; i++) {
		int mode;	scanf("%d", &mode);

		if (mode == 1) {
			int a, b, c;	scanf("%d %d %d", &a, &b, &c);
			if (a > b) swap(a, b);

			update(1, 1, start_i, a, b, c);
		}
		else {
			int a, b;	scanf("%d %d", &a, &b);
			if (a > b) swap(a, b);

			printf("%lld\n", getSum(1, 1, start_i, a, b));
		}
	}

	return 0;
}
