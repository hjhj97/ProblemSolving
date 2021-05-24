#include<stdio.h>
#include<math.h>
#define SIZE 1000001
#define TREESIZE 4123456
int tree_size,start_i;
int tree[TREESIZE];
void update(int i, int a) {
	tree[i] += a;
	int par = i / 2;

	while (par >= 1) {
		tree[par] = tree[par * 2] + tree[par * 2 + 1];
		par /= 2;
	}
	return;
}
int give_candy(int cur_node,int i) {
		int ans;

		while (1) {
			int l = cur_node * 2, r = cur_node * 2 + 1;

			if (cur_node >= start_i) { //사탕 번호 출력
				ans = cur_node;
				ans = ans- start_i + 1;
				update(cur_node, -1);
				return ans;
			}

			if (i > tree[l]) { //오른쪽으로
				cur_node = cur_node * 2 + 1;
				i -= tree[l];
			}
			else { //왼쪽으로
				cur_node = cur_node * 2;
			}

		}
}
int main() {
	int n;	scanf("%d", &n);
	int power = ceil(log2(SIZE));
	start_i = 1 << power;
	tree_size = start_i * 2;

	while (n--) {

		int a;	scanf("%d", &a);

		if (a == 1) { //b순위 꺼내는 사탕의 번호출력
			int b;	scanf("%d", &b);
			printf("%d\n",give_candy(1, b));
		}

		else if (a == 2) {//b번 맛 사탕을 c개 넣음(뺌)
			int b, c;	scanf("%d %d", &b, &c);
			update(start_i + b - 1, c);
		}
	}
	return 0;
}
