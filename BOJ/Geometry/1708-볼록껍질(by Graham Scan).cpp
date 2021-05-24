#include<stdio.h>
#include<algorithm>
#include<stack>
#define SIZE 100000
using namespace std;
typedef long long ll;
struct Point {
	int x, y;

	const bool operator<(const Point &o) {
		if (x != o.x)	return x < o.x;
		else return y < o.y;
	}
};
Point point[SIZE + 10];
stack <int> s;
int ccw(Point a, Point b, Point c) {
	ll result = (ll)a.x*b.y + b.x*c.y + c.x * a.y - ((ll)a.x*c.y + b.x*a.y + c.x*b.y);

	if (result > 0)	return 1;
	else if (result < 0)	return -1;
	else return 0;
}
bool ccw_sort(Point a, Point b) {
	if (ccw(point[0], a, b) != 0)
		return ccw(point[0], a, b) > 0;

	return a < b;
}
int main() {
	int n;	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &point[i].x, &point[i].y);

	sort(point, point + n);
	sort(point + 1, point + n, ccw_sort);

	s.push(0);
	s.push(1);

	for (int i = 2; i < n; i++) {
		while (s.size() >= 2) {
			int top = s.top();	s.pop();
			int sec_top = s.top();

			if (ccw(point[sec_top], point[top], point[i]) > 0) {
				s.push(top);
				s.push(i)
				break;
			}
		}
		if (s.size() < 2) s.push(i);
	}

	printf("%d\n", s.size());
	return 0;
}
/*
8
1 1
1 2
1 3
2 1
2 2
2 3
3 1
3 2
*/
