#include<stdio.h>
#include<queue>
#define SIZE 100
using namespace std;
struct Pos {
	int y, x, head;

	Pos(int _y, int _x, int _head) {
		y = _y;
		x = _x;
		_head = head;
	}
};
int count = 0;
int map[SIZE + 10][SIZE + 10];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
bool visited[SIZE + 10][SIZE + 10] = { false };
queue<Pos> q;
int main() {
	int c, r;	scanf("%d %d", &r, &c);

	//1 base
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			scanf("%d", &map[i][j]);

	int st_y, st_x, st_head;
	int end_y, end_x, end_head;
	scanf("%d %d %d", &st_y, st_x, &st_head);
	scanf("%d %d %d", &end_y, &end_x, &end_head);

	q.push(Pos(st_y, st_x, st_head));

	while (!q.empty()) {
		Pos cur = q.front();	q.pop();
		if (cur.y == end_y && cur.x == end_x)	break;

		for (int i = 0; i < 4; i++) {
			int nexti = cur.y + dy[i];
			int nextj = cur.x + dx[i];

			if (!visited[nexti][nextj] && map[nexti][nextj]==0) {

				q.push(Pos(nexti,nextj,))
			}
		}

	}

}
