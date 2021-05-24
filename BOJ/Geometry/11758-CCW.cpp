#include<stdio.h>
struct Point {
	int x, y;
};
int main() {
	Point point[3];

	for (int i = 0; i < 3; i++)
		scanf("%d %d", &point[i].x, &point[i].y);

	int result = point[0].x*point[1].y + point[1].x*point[2].y + point[2].x*point[0].y
		- (point[0].x*point[2].y + point[1].x*point[0].y + point[2].x * point[1].y);

	if (result == 0)	printf("0");

	else if (result > 0) printf("1");

	else printf("-1");

	return 0;
}
