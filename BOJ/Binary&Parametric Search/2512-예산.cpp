#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 11111
typedef long long ll;
int n;
ll bgt[SIZE];
ll fmini(ll a, ll b) {
	return (a > b) ? b : a;
}
ll fsum(ll base) {
	ll result = 0;
	for (int i = 0; i < n; i++)
		result += (fmini(base, bgt[i]));

	return result;
}
int main() {
	int k;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%lld", &bgt[i]);

	scanf("%d", &k);
	sort(bgt, bgt + n);


	ll l = 0, r = bgt[n - 1], mid, cur,ans;
	while (r >= l) {
		mid = (l + r) / 2;
		cur = fsum(mid);

		if (cur == k) {
			printf("%lld\n", mid);
			return 0;
		}

		if (cur >= k) {
			r = mid - 1;
		}
		else {
			ans = mid;
			l = mid + 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
/*
4
120 110 140 150
519
*/
