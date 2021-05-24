#include<stdio.h>
int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a%b);
}
int main() {
	int a, b;	scanf("%d %d", &a, &b);

	printf("%d\n", gcd(a, b));

	return 0;
}
/*
Best Case: O(1)
Worst Case:O(log n);
*/
