#include<stdio.h>
int main() {
	int n;	scanf("%d", &n);
	int Y=0, M=0;

	for (int i = 0,call; i < n; i++) {
		scanf("%d", &call);

		Y += (call / 30 + 1) * 10;
		M += (call / 60 + 1) * 15;
	}
	if (Y > M)
		printf("M %d\n", M);

	else if (Y < M)
		printf("Y %d\n", Y);

	else printf("Y M %d\n",Y);

	return 0;
}
