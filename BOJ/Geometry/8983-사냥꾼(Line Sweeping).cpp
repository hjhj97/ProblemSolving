#include<stdio.h>
#include<algorithm>
#define SIZE 100009
using namespace std;
typedef pair<int, int> Cord;
bool operator <(const Cord &a, const Cord &b) {
	return a.first < b.first;
}
Cord ani[SIZE];
int shoot[SIZE];
int fAbs(int a) {
	return a > 0 ? a : -a;
}
int main() {
	int m, n, l;	scanf("%d %d %d", &m, &n, &l);

	for (int i = 0; i < m; i++) {
		scanf("%d", &shoot[i]);
	}
	for (int i = 0; i < n; i++) {
		int a, b;	scanf("%d %d", &a, &b);
		ani[i] = make_pair(a, b);
	}
	sort(shoot, shoot + m);
	sort(ani, ani + n);

	int ans = 0, x_shoot;

	for (int i = 0, idx = 0; i < n; i++) {
		if (idx<m - 1)
			while (fAbs(shoot[idx] - ani[i].first) > fAbs(shoot[idx + 1] - ani[i].first)) {
				idx++;
			}

		x_shoot = shoot[idx];
		int dist = fAbs(x_shoot - ani[i].first) + ani[i].second;

		if (dist <= l) ans++;

	}
	printf("%d\n", ans);
	return 0;
}
