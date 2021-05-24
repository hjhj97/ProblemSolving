#include<stdio.h>
#include<math.h>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
#define SIZE 500010
int start_i, tree_size;
int tree[SIZE*2];
int num[SIZE],sorted[SIZE];
set<int> checkSet;
ll getCount(int cur_node, int ql, int qr, int cl, int cr) {
	if (ql > cr || qr < cl)
		return 0;

	if (ql <= cl && qr >= cr)
		return tree[cur_node];

	int mid = (cl + cr) / 2;
	return getCount(cur_node * 2, ql, qr, cl, mid) + getCount(cur_node * 2 + 1, ql, qr, mid + 1, cr);
}
void update(int num) {
	tree[num]++;
	int par = num / 2;

	while (par >= 1) {
		tree[par] = tree[par * 2] + tree[par * 2 + 1];
		par /= 2;
	}
	return;
}
int main() {
	int n, idx = 1;	scanf("%d", &n);
	ll ans = 0;

	int powNum = ceil(log2(n));
	start_i = 1 << powNum;
	tree_size = start_i * 2;

	for (int i = 0 ; i < n; i++) {
		scanf("%d", &num[i]);

		if (checkSet.count(num[i])) //중복 되어있으면
			continue;
		checkSet.insert(num[i]);
		sorted[idx++] = num[i];
	}

	sort(sorted+1, sorted + idx);

	for (int i = 0; i < n; i++) {
		int pos, l = 1, r = idx;
		 //pos-> 0 base
		while (r >= l) {
			pos = (l + r) / 2;

			if (sorted[pos] == num[i])
				break;

			else if (sorted[pos] > num[i])
				r = pos - 1;
			else l = pos + 1;
		}
		ans += getCount(1, pos+1, idx, 1, start_i); //세그먼트 트리는 1 base이므로 1을 또 더해줌.
		update(start_i + pos-1);
	}


	printf("%lld\n", ans);

	return 0;
}
/*
7
3 -99 17 8 5 99 3
->8

6
3 -99 17 8 5 99
->4

4
2 1 1 3
->2
*/
