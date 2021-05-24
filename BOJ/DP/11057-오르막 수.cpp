#include<stdio.h>
int main() {
	int n,now=1;	scanf("%d", &n);
	long long count, pre_count=10;
	long long dp[10] = { 0,1,1,1,1,1,1,1,1,1 };

	if (n == 1)
		count = 10;

	while(now!=n){
		long long dp_new[10] = { 0 };
		count = 0;

		for (int i = 1; i <= 9; i++)
			for (int j = i; j <= 9; j++)
				dp_new[i] = (dp_new[i] + dp[j])%10007;

		for (int i = 1; i <= 9; i++)
			count += (dp_new[i]);

		count += pre_count;
		pre_count = count;

		for (int i = 1; i <= 9; i++)
			dp[i] = dp_new[i];

		now++;
	}


	printf("%lld\n",count%10007);

	return 0;
}
