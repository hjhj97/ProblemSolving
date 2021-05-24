#include<stdio.h>
#include<queue>
#define SIZE 50
using namespace std;
struct Pos {
	int y, x;

	Pos(int _y, int _x) {
		y = _y;
		x = _x;
	}
};
queue<Pos>q;
char map[SIZE + 5][SIZE + 5];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int start_i, start_j;
int end_i, end_j;
int main() {
	int r, c;	scanf("%d %d ", &r, &c);

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c + 1; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'S') {
				start_i = i;	start_j = j;
			}
			else if (map[i][j] == 'D') {
				end_i = i;	end_j = j;
			}
		}

	q.push(Pos(start_i, start_j));

	while (!q.empty()) {
		Pos cur = q.front();	 q.pop();


	}


}
