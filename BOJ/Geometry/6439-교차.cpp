#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 3000
struct Point {
	int x, y;

	const bool operator <(const Point &o) {
		return x < o.x && y < o.y;
	}
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
		if (a.end < a.st)	swap(a.st, a.end);
		if (b.end < b.st)	swap(b.st, b.end);

		return !(a.end < b.st || b.end < a.st);
	}
	return result1 <= 0 && result2 <= 0;
}
int SegCount[SIZE + 10], SegIdx[SIZE + 10];
Seg seg[SIZE + 10];
int main() {
	int n, max_count = 0, group_count=0;	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		bool not_crossed = true;
		scanf("%d %d %d %d", &seg[i].st.x, &seg[i].st.y, &seg[i].end.x, &seg[i].end.y);

		for (int j = 0; j < i; j++) {
			group_count = 1;
			if (isCross(seg[i], seg[j])) {
				int cur_SegIdx = SegIdx[i];
				SegIdx[j] = cur_SegIdx;
				SegCount[cur_SegIdx]++;
				not_crossed = false;
			}
		}
		if (not_crossed) {  //i선분이 어떤 선분과도 교차하지 않으면
			SegIdx[i] = group_count++;
			SegCount[SegIdx[i]]++;
		}
	}

	for (int i : SegCount)
		max_count = (max_count < i) ? i : max_count;

	printf("%d\n%d\n", group_count, max_count);

	return 0;
}
/*
3
1 1 2 3
2 1 0 0
1 0 1 1
->1 3
3
0 1 10 1
1 2 1 0
2 2 2 0
->1 3
3
1 2 1 0
2 2 2 0
0 1 10 1
->1 3
4
0 0 1 0
1 0 1 1
1 1 0 1
0 1 0 0
->1 4
4
1 1 2 2
3 3 4 4
5 5 6 6
7 7 8 8
->4 1
*/
