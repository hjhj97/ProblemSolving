#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	int n,ans=0;	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b, c;	scanf("%d %d %d", &a, &b, &c);
		int cur = 0;
		if (a == b && b == c) {
			cur = 10000 + 1000 * a;
		}
		else if (a==b || a==c) {
			cur = 1000 + 100 * a;
		}
		else if (b == c) {
			cur = 1000 + 100 * b;
		}
		else {
			cur = 100 * max(a, max(b, c));
		}
		ans = max(ans, cur);
	}
	printf("%d\n", ans);
	return 0;
}
