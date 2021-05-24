#include<stdio.h>
int num[1010];
int main() {
	int a, b,ans=0,last=0;	scanf("%d %d", &a, &b);

	for (int i = 1; i <= 50;i++)
		for (int j = last+1, count = 1; count <= i; count++, j++) {
			num[last] = i;
			last = j;
		}
	for (int i = a-1; i <= b-1; i++)
		ans += (num[i]);

	printf("%d\n", ans);

	return 0;
}
