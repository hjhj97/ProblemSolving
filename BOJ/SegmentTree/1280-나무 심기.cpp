#include<stdio.h>
#include<math.h>
using namespace std;
#define MOD 1000000007
#define SIZE 200010
typedef long long ll;
int start_i, tree_size;
ll sum_tree[SIZE * 8];
ll count_tree[SIZE * 8];
int arr[SIZE];
ll getSum(int cur_node, int ql, int qr, int cl, int cr) {
	if (ql > cr || qr < cl)
		return 0;

	if (ql <= cl && qr >= cr)
		return sum_tree[cur_node] % MOD;

	int mid = (cl + cr) / 2;
	return (getSum(cur_node * 2, ql, qr, cl, mid) % MOD)
		+ (getSum(cur_node * 2 + 1, ql, qr, mid + 1, cr) % MOD) % MOD;

}
ll getCount(int cur_node, int ql, int qr, int cl, int cr) {
	if (ql > cr || qr < cl)
		return 0;

	if (ql <= cl && qr >= cr)
		return count_tree[cur_node];

	int mid = (cl + cr) / 2;
	return getCount(cur_node * 2, ql, qr, cl, mid) + getCount(cur_node * 2 + 1, ql, qr, mid + 1, cr);

}
void sum_update(int num) {
	sum_tree[start_i + num] += num;
	int par = (start_i + num) / 2;

	while (par >= 1) {
		sum_tree[par] = (sum_tree[par * 2] + sum_tree[par * 2 + 1]) % MOD;
		par /= 2;
	}
	return;
}
void count_update(int num) {
	count_tree[start_i + num]++;
	int par = (start_i + num) / 2;

	while (par >= 1) {
		count_tree[par] = count_tree[par * 2] + count_tree[par * 2 + 1];
		par /= 2;
	}
	return;
}

int main() {
	int n, sum = 0;	scanf("%d", &n);
	ll ans = 1;

	int powNum = ceil(log2(SIZE));
	start_i = 1 << powNum;
	tree_size = start_i * 2;

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++) {
		int num = arr[i];

		if (i != 0) {
			ll a1 = ((num*getCount(1, 1, num, 1, start_i) % MOD - getSum(1, 1, num, 1, start_i)%MOD)+MOD) % MOD ;
			ll a2 = ((getSum(1, num + 1, SIZE - 10, 1, start_i) % MOD - num*getCount(1, num + 1, SIZE - 10, 1, start_i)%MOD)+MOD)%MOD;

			ans *= (a1 + a2) % MOD;
			ans %= MOD;

		}
		sum_update(num);
		count_update(num);
	}
	printf("%lld\n", ans%MOD);
	return 0;
}
