#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int n, arr[100100], tmp[100100],max=-9999; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	tmp[0] =arr[0];

	for (int i = 1; i <n; i++) { //더한 값 vs 배열 하나 값
		if (arr[i] <= tmp[i-1] + arr[i]) //더한 값이 더 크면
			tmp[i] = tmp[i-1] + arr[i];
		else //배열 값 자체가 더 크면
			tmp[i] = arr[i];
	}
	for (int i = 0; i < n; i++)
		max = (max > tmp[i]) ? max : tmp[i];


		printf("%d\n", max);

	return 0;
}
