#include<stdio.h>
#include<algorithm>
using namespace std;
int L, K, C, first_cut = -1, tmp;
int cut[10010];

int find(int base) {
	int cnt = 0;
	for (int i = 0; i <= K; ) {
		if (cut[i + 1] - cut[i] > base)
			return -1;

		for (int j = 0;  ; j++) {
			if (cut[i + j + 1] - cut[i] > base) {
				cnt++;
				i = i + j;
				break;
			}
		}
	}
	return cnt -1;
}
int main() {
	scanf("%d %d %d", &L, &K, &C);

	for (int i = 1; i <= K; i++) {
		scanf("%d", &cut[i]);
	}

	cut[0] = 0, cut[K + 1] = L;
	sort(cut, cut + K + 2);
	cut[K + 2] = (int)2e+9;

	int l = 0, r = L, mid;

	//lower bound search
	while (r >= l) {
		mid = (l + r) / 2;

		int result = find(mid);
		if (result == -1 || result > C)
			l = mid + 1;

		else {
			r = mid - 1;
			tmp = mid;
		}
	}

	for (int i = 1; i <= K; i++) {
		int cnt = 0;

		for (int j = i; j <= K; ) {

			for (int x = 0; ; x++) {
				if (cut[j + x + 1] - cut[j] > tmp) {
					cnt++;
					j = j + x;
					break;
				}
			}
		}

		if (cnt <= C) {
			first_cut = cut[i];
			break;
		}
	}


	printf("%d %d\n", tmp, first_cut);

	return 0;
}
/*
20 3 2
5 12 17
->8 5

20 4 4
4 8 12 16
->4 4

20 2 1
4 10
->10 10

20 3 2
7 10 15
->8 7

30 3 3
5 10 15
->15 5

30 3 3
15 20 25
->15 15
*/
