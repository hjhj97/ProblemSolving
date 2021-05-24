#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 11111
long long line[SIZE];	int n;
long long cut(int base) {
	long long count = 0;
	for (int i = 0; i < n; i++)
		count += (line[i] / base);

	return count;
}
int main() {
	int k;	scanf("%d %d", &n, &k);
	long long max = 0;

	for (int i = 0; i < n; i++)
		scanf("%lld", &line[i]);

	sort(line, line + n);

	long long l = 1, r = line[n - 1];
	long long mid, cur,ans=0;
	while (r >= l) {
		mid = (l + r) / 2;
		cur = cut(mid);

		if (cur >= k) {//너무 잘게 잘라서 랜선 개수가 많이나옴
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}
