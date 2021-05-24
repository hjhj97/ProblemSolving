#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int n, stair[333], dp[333], result = 0; scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &stair[i]);

	dp[0] = 0;  dp[1] = stair[1]; dp[2] = stair[1] + stair[2];


	if (n >= 3) {
		for (int i = 3; i <= n; i++) {
				result = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
            /*
            문제 조건상 계단 세칸 이상은 뛰어 넘을 수 없기 때문에 dp[i-1]은 max비교연산에 포함될 수 없다
            왜냐하면 dp[i-1]이 포함되면 100 100 1 1 2 2의 조합이 있을 때, 100이 압도적으로 큰 수이기 때문에
            1,1은 거의 무시된다. 그러므로 dp[i-1]이 반드시 max의 비교연산에서 선택될 것이고 100,100,2,2가 뽑혀서
            계단을 세칸씩 뛰어 넘게 되는 것이다.
             */

			dp[i] = result;
		}
	}

	printf("%d\n", dp[n]);

	return 0;
}
/*
6
10 20 15 25 10 20

6
2 2 1 1 2 2
->7
*/
