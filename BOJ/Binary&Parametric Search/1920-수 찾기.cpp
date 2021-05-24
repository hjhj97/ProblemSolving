#include<stdio.h>
#include<algorithm>
#define SIZE 100100
using namespace std;
int arr[SIZE];
int main() {
	int n;	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);

	int m;	scanf("%d", &m);

	for(int i=0 ; i<m ; i++) {
		int tgt;	scanf("%d", &tgt);
		bool flag = true;
		int l = 0, r = n-1, mid;

		while (r >= l) {
			mid = (l + r) / 2;

			if (arr[mid] == tgt) {
				printf("1\n");
				flag = false;
				break;
			}
			if (tgt > arr[mid])
				l = mid + 1;

			else r = mid - 1;
		}
		if (flag)
			printf("0\n");
	}

	return 0;
}
