#include<stdio.h>
int num[20],arr[20];
int count = 0,n,s;
void recur(int cur, int last,int pre_sum) {
	int sum = 0;
	if (cur != 0) {
		sum = pre_sum + num[arr[cur-1]];
	}
	if (cur!=0 && sum == s)	count++;

	for (int i = last + 1; i < n; i++) {
		arr[cur] = i;
		recur(cur + 1, i,sum); //인자로 sum값을 넘김(메모이제이션)
	}
	return;
}
int main() {
	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	recur(0,-1,0);


	printf("%d\n", count);

	return 0;
}
