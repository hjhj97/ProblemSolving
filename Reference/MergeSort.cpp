#include<stdio.h>
int arr[10] = { 61,59,48,37,26,19,15,11,5,1 };
void merge(int L,int M,int R) {
	int sorted[10];
	int l = L, r = M + 1,idx=L;

	while (l <= M && r <= R) {
		if (arr[l] > arr[r])	sorted[idx++] = arr[r++];
		else sorted[idx++] = arr[l++];
	}
	if (r > R)
		for (int i = l; i <= M; i++)
			sorted[idx++] = arr[i];
	else for (int i = r; r <= R; i++)
		sorted[idx++] = arr[i];

	for (int i = L; i <= R; i++)
		arr[i] = sorted[i];
}
void mergeSort(int l,int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mergeSort(l, mid);
		mergeSort(mid + 1, r);
		merge(l,mid,r);
	}
}
int main() {
	int size = 10;
	mergeSort(0, size - 1);

	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);

	return 0;
}
