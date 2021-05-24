#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 10009
struct Tree {
	int to, dist;

	Tree() {}
	Tree(int _to, int _dist) {
		to = _to;
		dist = _dist;
	}
};
int n, ans = 0;
vector<Tree> tree[SIZE];
int fMax(int a, int b) {
	return a > b ? a : b;
}
int func(int cur_node) {
	if (tree[cur_node].size() == 0)
		return 0;

	vector<int> two_max_num;

	for (auto nx : tree[cur_node]) {
		int next = nx.to;
		int next_sum = func(next) + nx.dist;

		two_max_num.push_back(next_sum);
	}

	sort(two_max_num.begin(), two_max_num.end());

	int size = two_max_num.size(), sum = 0, tmp = two_max_num[size - 1];
	if (tree[cur_node].size() == 1) {
		sum = two_max_num[size - 1];
	}
	else sum = two_max_num[size - 1] + two_max_num[size - 2];
	ans = fMax(ans, sum);

	return tmp;
}
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;	scanf("%d %d %d", &a, &b, &c);
		tree[a].push_back(Tree(b, c));
	}
	func(1);
	printf("%d\n", ans);
	return 0;
}
