#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 1232123
long long tree[SIZE], n;
long long fsum(long long base) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (base < tree[i])
			sum += (tree[i] - base);
	}
	return sum;

}
int main() {
	int m;	scanf("%lld %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &tree[i]);
	}

	sort(tree, tree + n);

	long long l = 1, r = tree[n - 1], mid, cur,ans;

	//upper bound search
	//upper bound일때는 l조건에 ans값 저장.
	while (r >= l) {
		mid = (r + l) / 2;
		cur = fsum(mid);

		if (cur == m) {
			printf("%lld\n", mid);
			return 0;
		}

		if (cur > m) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	printf("%lld\n", ans);
	return 0;
}
/*
4 40
20 15 10 17
->5
*/
