#include<stdio.h>
#include<queue>
#define INF 1<<30
using namespace std;
struct Pos {
	int y, x, cost_left;

	Pos() {}
	Pos(int _y, int _x, int _cost_left) {
		y = _y;
		x = _x;
		cost_left = _cost_left;
	}
};
int n, m, t, d;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int max_dist[30][30] = { 0 };
char map[30][30];
queue<Pos> q;
int abs(int a) {
	return a > 0 ? a : -a;
}
int sqr(int a) {
	return a*a;
}
int fMax(int a, int b) {
	return a > b ? a : b;
}
int is_large(char letter) {
	if (letter >= 'A' && letter <= 'Z')	return 1;
	else return -1;
}
int get_cost(char cur, char next) {
	if (cur >= next) //높은곳-> 낮은곳
		return 1;

	else { //낮은곳-> 높은곳
		if (is_large(cur) == 1 && is_large(next) == -1) //대->소
			return sqr(next - cur - 6);
		else return sqr(next - cur);
	}
}
int main() {
	scanf("%d %d %d %d ", &n, &m, &t, &d);
	int max_point = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m + 1; j++)
			scanf("%c", &map[i][j]);

	q.push(Pos(0, 0, d));

	while (!q.empty()) {
		Pos cur = q.front();	q.pop();
		max_point = fMax(max_point, map[cur.y][cur.x] - 'A'); //
		printf("%d %d %d %c\n", cur.y, cur.x, cur.cost_left,map[cur.y][cur.x]);

		for (int i = 0; i < 4; i++) {
			int nexti = cur.y + dy[i];
			int nextj = cur.x + dx[i];
			if (nexti < 0 || nextj < 0 || nexti >= n || nextj >= m)	continue;
			int return_to_hotel = nexti + nextj;
			int cur_letter = map[cur.y][cur.x], next_letter = map[nexti][nextj];
			if (abs(cur_letter - next_letter) > t)	continue;
			int next_cost = get_cost(cur_letter, next_letter);

			if (cur.cost_left >= next_cost) {
				if (max_dist[nexti][nextj] < cur.cost_left-next_cost) {
					q.push(Pos(nexti, nextj, cur.cost_left - next_cost));
					max_dist[nexti][nextj] = cur.cost_left - next_cost;
				}
			}
		}
	}
	if (max_point >= 32)	max_point -= 6;
	printf("*%d\n", max_point);
	return 0;
}
