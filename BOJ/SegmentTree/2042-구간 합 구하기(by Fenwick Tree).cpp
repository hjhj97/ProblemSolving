//Fenwick Tree
#include<stdio.h>
#define SIZE 1234567
int n;
long long arr[SIZE];
long long tree[SIZE];
long long sum(int i) {
	long long ans = 0;

	while (i>0) {
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}
void update(int i, long long a) {

	while (i <n+1) {
		tree[i] += a;
		i += (i&-i);
	}
	return;
}
int main() {
	int m, k;	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		long long a;
		scanf("%lld", &arr[i]);
		update(i, arr[i]);
	}
	for(int i=0 ; i<k+m ; i++) {
		int a;	scanf("%d", &a);

		//1일때는 update, 2일땐는 sum
		if (a == 1) {
			int b; long long c;	scanf("%d %lld", &b, &c);
			long long gap = c - arr[b];
            arr[b]=c;
			update(b, gap);

		}
		else if (a == 2) {
			int b, c;	scanf("%d %d", &b, &c);
			printf("%lld\n", sum(c) - sum(b - 1));
		}
	}
	return 0;
}
