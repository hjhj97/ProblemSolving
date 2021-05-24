#include<stdio.h>
#include<algorithm>
using namespace std;
struct s {
	int coin, n_coin; //coin은 동전의 금액, n_coin은 동전의 개수

	const bool operator < (const s&o)const { //cost가 작은 순서대로 정렬하기 위한 연산자 정의
		return coin < o.coin;
	}
};
s c[110];
int dp[110][10001];
int main() {
	int cost, n, count = 0; //dp[cost]=b ->cost만큼의 금액을 교환할 수 있는 경우의 수 b개

	scanf("%d", &cost);
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d %d", &c[i].coin, &c[i].n_coin);

	sort(c, c + n);
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= c[i].n_coin; j++) {
			for (int k = 0; k <= cost; k++) {
				if (k + c[i].coin*j > cost)
					break;

				dp[i][k + c[i].coin*j] += dp[i - 1][k];
			}
		}

	}
	printf("%d\n", dp[n][cost]);

	return 0;

}
