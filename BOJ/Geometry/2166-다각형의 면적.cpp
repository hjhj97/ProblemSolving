#include<stdio.h>
#define SIZE 10000
typedef long long ll;
struct Point {
	double x, y;
};
Point sq[SIZE + 10];
double ans = 0;
double fAbs(double a) {
	return a > 0 ? a : -a;
}
ll ccw(Point a, Point b, Point c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - (a.x*c.y + b.x*a.y + c.x*b.y);
}

int main() {
	int n;	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%lf %lf", &sq[i].x, &sq[i].y);

	for (int i = 0; i < n - 2; i++)
		ans += ccw(sq[0], sq[i + 1], sq[i + 2]) / 2.0;

	printf("%.1f\n", fAbs(ans));

	return 0;
}
