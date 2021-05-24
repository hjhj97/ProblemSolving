#include<stdio.h>
typedef long long ll;
int main() {
	ll sum = 0;
	char num1[10001], num2[10001];
	scanf("%s %s", num1, num2);

	for(int i=0 ; num1[i]!=0 ; i++)
		for (int j = 0; num2[j] != 0; j++) {
			sum += (num1[i] - '0')*(num2[j] - '0');
		}

	printf("%lld\n", sum);

	return 0;
}
