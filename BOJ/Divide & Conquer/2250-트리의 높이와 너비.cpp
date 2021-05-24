#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define SIZE 10009
struct Tree {
	int l, r, level;

	Tree() {}
	Tree(int _l, int _r, int _level) {
		l = _l;
		r = _r;
		level = _level;
	}
};
vector<int> breadth[SIZE];
Tree tree[SIZE];
int pos[SIZE];//1 base
bool check[SIZE] = { false };

int dfs(int cur, int move, int level) {
	auto tmp = tree[cur];
	tree[cur].level = level;
	int nextL = tmp.l, cnt_L;

	if (nextL == -1) cnt_L = 0;
	else cnt_L = dfs(nextL, move, level + 1);

	move += cnt_L;
	pos[cur] = move;

	int nextR = tmp.r, cnt_R;
	if (nextR == -1) cnt_R = 0;
	else cnt_R = dfs(nextR, move + 1, level + 1);

	if (cnt_L + cnt_R == 0) return 1; //리프 노드인 경우
	return cnt_L + cnt_R + 1;
}
int main() {
	int n, root;	scanf("%d", &n);

	int max_level = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c;	scanf("%d %d %d", &a, &b, &c);
		int cur_level = tree[a].level;

		tree[a] = Tree(b, c, 0);

		if (b != -1) check[b] = true;
		if (c != -1) check[c] = true;
	}

	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			root = i;
			break;
		}
	}

	dfs(root, 1, 1);

	int ans_level, ans_breadth = 0;
	for (int i = 1; i <= n; i++) {
		int cur_level = tree[i].level;
		breadth[cur_level].push_back(pos[i]);
		max_level = max(max_level, cur_level);
	}


	for (int i = 1; i <= max_level; i++) {
		sort(breadth[i].begin(), breadth[i].end());
		int gap = breadth[i][breadth[i].size() - 1] - breadth[i][0] + 1;

		if (ans_breadth < gap) {
			ans_level = i;
			ans_breadth = gap;
		}
	}

	printf("%d %d\n", ans_level, ans_breadth);

	return 0;
}
/*
3
1 2 -1
2 3 -1
3 -1 -1

3
1 -1 2
2 -1 3
3 -1 -1
*/
