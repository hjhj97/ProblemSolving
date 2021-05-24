#include<stdio.h>
#include<math.h>
#include<algorithm>
#define SIZE 500100
#define MAX_NUM 1000000
typedef long long ll;
using namespace std;
int firstNum[SIZE], secNum[SIZE],idx[MAX_NUM+1];
ll tree[SIZE * 4];
int start_i, tree_size;
ll getCount(int cur_node, int ql, int qr, int cl, int cr) {
	if (ql > cr || qr < cl)
		return 0;

	if (ql<=cl && qr>=cr)
		return tree[cur_node];

	int mid = (cl + cr) / 2;
	return getCount(cur_node * 2, ql, qr, cl, mid) + getCount(cur_node * 2 + 1, ql, qr, mid + 1, cr);

}
void update(int cur_node) {
	tree[start_i + cur_node]++;
	int par = (start_i + cur_node) / 2;

	while (par >= 1) {
		tree[par] = tree[par * 2] + tree[par * 2 + 1];
		par /= 2;
	}
	return;
}
int main() {
	ll ans = 0;
	int n;	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &firstNum[i]);
		idx[firstNum[i]] = i;
	}

	for (int i = 0; i < n; i++)
		scanf("%d", &secNum[i]);

	int powNum = ceil(log2(n));
	start_i = 1 << powNum;
	tree_size = start_i * 2;

	for (int i = 0; i < n; i++) {
		ans += getCount(1,idx[secNum[i]]+1,MAX_NUM,1,start_i);
		update(idx[secNum[i]]); //idx -> 0 base
	}
	printf("%lld\n", ans);

	return 0;
}
