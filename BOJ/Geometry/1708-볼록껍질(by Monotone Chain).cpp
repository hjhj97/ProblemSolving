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

int main() {
	int n;	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &point[i].x, &point[i].y);

	sort(point, point + n);

	s.push(0);
	s.push(1);

	for (int i = 2; i < n; i++) {
		while(s.size()>=2) {
			int top = s.top();	s.pop();
			int sec_top = s.top();

			if (ccw(point[sec_top], point[top], point[i]) > 0) {
				s.push(top);
				s.push(i);
				break;
			}
		}
		if (s.size() < 2)	s.push(i);
	}
	int Lcount = s.size()+1;

	for (int i = n - 2; i >= 0; i--) {
		while (s.size() >= Lcount) {
			int top = s.top();	s.pop();
			int sec_top = s.top();

			if (ccw(point[sec_top], point[top], point[i])>0) {
				s.push(top);
				s.push(i);
				break;
			}
		}
		if (s.size() < Lcount)	s.push(i);
	}

	printf("%d\n", s.size()-1);
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
