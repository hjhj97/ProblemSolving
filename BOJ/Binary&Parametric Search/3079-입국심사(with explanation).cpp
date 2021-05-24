#include<stdio.h>
#include<math.h>
#include<algorithm>
#define SIZE 100100
#define INF 1e+15
using namespace std;
typedef long long ll;
ll line[SIZE];
int n;
ll func(ll cur) {
	ll result = 0;

	for (int i = 0; i < n; i++)
		result += (cur / line[i]);

	return result;
}
int main() {
	int  m;	scanf("%d %d", &n, &m);
	ll ans = INF;
	for (int i = 0; i < n; i++)
		scanf("%lld", &line[i]);

	sort(line, line + n);

	int mul = ceil((double)m / n);

	ll l = mul*line[0], r = mul*line[n - 1], mid;
	//lower bound search
	/*
	lower bound일때는 r조건에 ans값 저장.
	가장 마지막 loop에서 r=mid-1연산을 수행했는데,
	줄어든 r값이 답이 될 수 없다면 r값을 줄이기 이전의 값이 최적의 답인 것이다.
	*/
	while (r >= l) {
		mid = (l + r) / 2;
		ll cur = func(mid);

		if (cur >= m) {
			ans = mid;
			r = mid - 1;
		}

		else l = mid + 1;
	}
	printf("%lld\n", ans);

	return 0;
}
/*
2 6
7
10
*/
