#include<stdio.h>
typedef long long ll;
#define SIZE 100100
int tree[SIZE * 8]; ll h[SIZE];
int start_i, tree_size, n;
ll fMin(ll a, ll b) {
	return a > b ? b : a;
}
ll fMax(ll a, ll b) {
	return a > b ? a : b;
}
ll fMax(ll a, ll b, ll  c) {
	return fMax(a, b) > c ? fMax(a, b) : c;
}
int make_tree(int cur_idx, int l, int r) {
	if (r == l) {
		return tree[cur_idx] = l;
	}

	int mid = (l + r) / 2;
	int l_idx = make_tree(cur_idx * 2, l, mid);
	int r_idx = make_tree(cur_idx * 2 + 1, mid + 1, r);

	if (h[l_idx] > h[r_idx]) {
		return tree[cur_idx] = r_idx;
	}
	else return tree[cur_idx] = l_idx;
}
int getSmallestIdx(int cur_idx, int cl, int cr, int ql, int qr) {
	if (qr<cl || ql>cr)
		return -1;
	if (qr >= cr && ql <= cl)
		return tree[cur_idx];

	int mid = (cl + cr) / 2;
	int l_idx = getSmallestIdx(cur_idx * 2, cl, mid, ql, qr);
	int r_idx = getSmallestIdx(cur_idx * 2 + 1, mid + 1, cr, ql, qr);
	if (l_idx == -1)	return r_idx;
	else if (r_idx == -1)	return l_idx;

	if (h[r_idx] > h[l_idx])
		return l_idx;
	else return r_idx;

}
ll getMax(int l, int r) {
	if (r <= l) {
		return h[tree[r+start_i]];
	}

	int cur_min_idx = getSmallestIdx(1, 0, n - 1, l, r);
	ll cur_area = (r - l + 1)*h[cur_min_idx];
	ll l_area = -1, r_area = -1;

	if (l <= cur_min_idx - 1) {
		l_area = getMax(l, cur_min_idx - 1);
	}

	if (r >= cur_min_idx + 1) {
		r_area = getMax(cur_min_idx + 1, r);
	}

	return fMax(cur_area, l_area, r_area);

}
void clear() {
	for (int i = 0; i <= tree_size; i++) {
		tree[i] = 0;
	}
	for (int i = 0; i <= n; i++)
		h[i] = 0;
}
int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0)	break;

		for (start_i = 1; start_i < n; start_i *= 2);
		tree_size = start_i * 2;

		for (int i = 0; i < n; i++) {
			scanf("%lld", &h[i]);
			tree[start_i + i] = i;
		}
		make_tree(1, 0, n - 1);

		printf("%lld\n", getMax(0, n - 1));

		clear();
	}
	return 0;
}
