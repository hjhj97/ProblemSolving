#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[100];
int Size, k;
void qSelection(int l, int r) {
	if (l >= r) return;

	int i = l + 1, j = r, pivot = arr[l];

	while (i <= j) {
		while (arr[i] < pivot && i <= j) i++;
		while (arr[j] >= pivot && i <= j) j--;

		if (i < j) swap(arr[i], arr[j]);
	}
	swap(arr[l], arr[j]);

	if (Size - j == k) {
		printf("%d-th greatest element : %d\n", k, arr[j]);
		return;
	}

	printf("%d는 %d번째로 큰 수입니다\n", arr[j], Size - j);
	if (Size - j > k) qSelection(j + 1, r);
	else qSelection(l, j - 1);

	return;
}
int main() {
	printf("Size: "); scanf("%d", &Size);
	printf("k-th element : ");	scanf("%d", &k);

	for (int i = 0; i < Size; i++)
		scanf("%d", &arr[i]);

	qSelection(0, Size - 1);

	return 0;
}
