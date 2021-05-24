#include<stdio.h>
#include<math.h>
#define SIZE 100100
int n, m;
int start_i, tree_size, last = 1;
int tree[SIZE * 8], dvd_pos[SIZE];
int make_tree(int cur_node) {
	if (cur_node >= start_i)
		return tree[cur_node];

	tree[cur_node] = make_tree(cur_node * 2) + make_tree(cur_node * 2 + 1);

	return tree[cur_node];
}
int getCount(int cur_node, int ql, int qr, int cl, int cr) {
	if (ql > cr || qr < cl)
		return 0;
	if (ql <= cl && qr >= cr)
		return tree[cur_node];

	int mid = (cl + cr) / 2;
	return getCount(cur_node * 2, ql, qr, cl, mid) + getCount(cur_node * 2 + 1, ql, qr, mid + 1, cr);
}
void update(int cur_num) { //cur_num : 이번에 빼낸 dvd의 번호
	int pre = dvd_pos[cur_num]; //dvd_pos[] : 빼낸 dvd의 위치
	tree[pre] = 0; //이전 위치 0으로 갱신

	int par = pre / 2;
	while (par >= 1) {
		tree[par] = tree[par * 2] + tree[par * 2 + 1];
		par /= 2;
	}

	int new_pos = (start_i + m - last); //new_pos : 새롭게 쌓은 dvd의 위치
	tree[new_pos] = 1;
	dvd_pos[cur_num] = start_i + m - last;
	new_pos /= 2;

	while (new_pos >= 1) {
		tree[new_pos] = tree[new_pos * 2] + tree[new_pos * 2 + 1];
		new_pos /= 2;
	}
	return;
}
int main() {
	int t;	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &m);
		int powNum = ceil(log2(n + m));
		start_i = (1 << powNum);
		tree_size = start_i * 2;

		for (int i = start_i + m; i < start_i + n + m; i++)
			tree[i] = 1;

		for (int i = 1; i <= n; i++)
			dvd_pos[i] = start_i + m + i - 1; //start_i base

		make_tree(1);

		for (int i = 0; i < m; i++) {
			int q, ans = 0;	scanf("%d", &q);
			ans = getCount(1, 1, dvd_pos[q] - start_i, 1, start_i);
			update(q);

			printf("%d ", ans);
			last++;
		}
		printf("\n");
		//0으로 set
		last = 1;
		for (int i = 0; i < tree_size; i++)
			tree[i] = 0;

		for (int i = 0; i <= n; i++)
			dvd_pos[i] = 0;


	}
	return 0;
}
