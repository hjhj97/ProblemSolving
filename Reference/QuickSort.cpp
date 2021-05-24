#include<stdio.h>
#include<algorithm>
#include<time.h>
using namespace std;
int arr[1000009];
int Size;
void qSort(int l, int r) {
	if (l >= r) return;

	int i = l + 1, j = r, random_idx = rand() % (r - l + 1) + l;
	swap(arr[l], arr[random_idx]);
	int pivot = arr[l];

	while (i <= j) {
		while (arr[i] < pivot && i <= j)i++;
		while (arr[j] >= pivot && i <= j) j--;

		if (i<j) swap(arr[i], arr[j]);
	}
	swap(arr[l], arr[j]);

	qSort(l, j - 1);
	qSort(j + 1, r);

	return;
}
int main() {
	scanf("%d", &Size);

	srand((unsigned int)time(NULL));
	for (int i = 0; i < Size; i++)
		scanf("%d", &arr[i]);

	qSort(0, Size - 1);

	for (int i = 0; i < Size; i++)
		printf("%d\n", arr[i]);

	return 0;
}
