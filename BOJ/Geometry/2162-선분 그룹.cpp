#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 3000
struct Point {
	int x, y;
};
struct Seg {
	Point st, end;
};
int ccw(Point a, Point b, Point c) {
	int result = (a.x*b.y + b.x*c.y + c.x*a.y) - (a.x*c.y + b.x*a.y + c.x*b.y);

	if (result > 0)	return 1;
	else if (result < 0)	return -1;
	else return 0;
}
bool isCross(Seg a, Seg b) {
	int result1, result2;
	result1 = ccw(a.st, a.end, b.st)*ccw(a.st, a.end, b.end);
	result2 = ccw(b.st, b.end, a.st)*ccw(b.st, b.end, a.end);

	if (result1 == 0 && result2 == 0) {
		if (a.st.y == b.st.y) {
			if (a.st.x > a.end.x)	swap(a.st.x, a.end.x);
			if (b.st.x > b.end.x)	swap(b.st.x, b.end.x);

			if (b.st.x > a.end.x || a.st.x > b.end.x)	return false;
			else return true;
		}
		else if (a.st.x == b.st.x) {
			if (a.st.y > a.end.y)	swap(a.st.y, a.end.y);
			if (b.st.y > b.end.y)	swap(b.st.y, b.end.y);

			if (b.st.y > a.end.y || a.st.y > b.end.y)	return false;
			else return true;
		}
	}
	return result1 <= 0 && result2 <= 0;
}
int SegIdx[SIZE + 10];
Seg seg[SIZE + 10];
int main() {
	int n,max_count=0,group_count=0;	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &seg[i].st.x, &seg[i].st.y, &seg[i].end.x, &seg[i].end.y);

		for (int j = 0; j < i; j++) {
			if (isCross(seg[i], seg[j])==false) { //두 선분이 교차하지 않으면

			}
		}
	}

	printf("%d\n%d", group_count, max_count);

	return 0;
}
