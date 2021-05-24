#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 1000009
#define START 1
#define END -1
struct Point {
	int cord, flag;

	const bool operator<(const Point &o) const {
		return cord < o.cord;
	}

	Point() {}
	Point(int _cord, int _flag) {
		cord = _cord;
		flag = _flag;
	}
};
Point point[SIZE * 2];
int n;
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b;	scanf("%d %d", &a, &b);

		point[2 * i] = Point(a, START);
		point[2 * i + 1] = Point(b, END);
	}
	sort(point, point + 2 * n);

	int ans = 0;
	for (int i = 0, cnt = 0; i < 2 * n; i++) {
		if (cnt >= 1) {
			ans += point[i].cord - point[i - 1].cord;
		}

		if (point[i].flag == START) {
			cnt++;
		}
		else { //END
			cnt--;
		}
	}
	printf("%d\n", ans);

	return 0;
}
