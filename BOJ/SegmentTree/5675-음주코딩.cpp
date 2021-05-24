#include<stdio.h>
#include<math.h>
#define SIZE 123456
#define TREESIZE 456789
int tree[TREESIZE];
int start_i, tree_size;

int make_tree(int cur_node) {
	if (cur_node >= start_i) {
		if (tree[cur_node] > 0)
			return tree[cur_node];

		else if (tree[cur_node] < 0)
			return tree[cur_node];

		else return 0;
	}

	return tree[cur_node] = make_tree(cur_node * 2)*make_tree(cur_node * 2 + 1);
}
void update(int i,int val){
	tree[i] = val;
	int par = i / 2;
	while (par >= 1) {
		tree[par] = tree[par * 2] * tree[par * 2 + 1];
		par /= 2;
	}
}
int find_status(int node,int ql,int qr,int cl,int cr){
	if (ql > cr || qr < cl)
		return 1;
	if (qr>=cr&&cl>=ql)
		return tree[node];

	int mid = (cl + cr) / 2;
	return find_status(node * 2, ql, qr, cl, mid)*find_status(node * 2 + 1, ql, qr, mid + 1, cr);

}
int main() {
	int n, k;
	while (scanf("%d %d",&n,&k)!=EOF) {

		int power = ceil(log2(n));
		start_i = 1 << power;
		tree_size = start_i * 2;

		for (int i = start_i; i < tree_size; i++)
			tree[i] = 1;

		for (int i = start_i; i < start_i + n; i++) {
			scanf("%d", &tree[i]);

			if(tree[i]!=0)
				tree[i] = (tree[i]> 0) ? 1 : -1;
		}

		make_tree(1);

		while(k--) {
			char q;	scanf(" %c ", &q);

			if (q == 'C') { //i번째를 v로 값을 변경
				int i, v;	scanf("%d %d", &i, &v);

				if(v!=0)
					v = (v > 0) ? 1 : -1;
				update(start_i + i - 1, v);
			}

			else if (q == 'P') { //a부터 b번째 까지의 곱의 부호 출력
				int a, b;	scanf("%d %d", &a, &b);
				int result = find_status(1, a, b, 1, start_i);

				if (result == 1)
					printf("+");
				else if (result == -1)
					printf("-");

				else printf("0");

			}
		}
		printf("\n");
		for (int i = 1; i <= tree_size; i++)
			tree[i] = 1;

	}

	return 0;
}
