#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define SIZE 10000
#define START 1
#define END -1
struct Map {
	int x, y, h, flag; //해당 좌표가 시작인지 끝인지 표시

	const bool operator <(const Map&o) const {
		return x < o.x;
	}

	Map() {}
	Map(int _x, int _y, int _h, int _flag) {
		x = _x;
		y = _y;
		h = _h;
		flag = _flag;
	};
};
int start_i, tree_size;
int tree[30000 * 8], lazy[30000 * 8], count_tree[30000 * 8];
Map map[2 * SIZE + 10];

void update(int cur_node, int check, int ql, int qr, int cl, int cr) {
	if (qr<cl || ql>cr)	return;

	if (qr >= cr && ql <= cl)	count_tree[cur_node] += check;

	else {
		int mid = (cl + cr) / 2;
		update(cur_node * 2, check, ql, qr, cl, mid);
		update(cur_node * 2 + 1, check, ql, qr, mid + 1, cr);
	}

	if (count_tree[cur_node] >= 1)	tree[cur_node] = cr - cl + 1;
	else {
		if (cur_node >= start_i)	tree[cur_node] = 0;
		else tree[cur_node] = tree[cur_node * 2] + tree[cur_node * 2 + 1];
	}

	return;
}
int main() {
	int n, ans = 0;	scanf("%d", &n);

	for (int i = 0, a, b, c, d; i < n; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		map[i * 2] = Map(a, b, d - b, START);
		map[i * 2 + 1] = Map(c, d, d - b, END);
	}

	int powNum = ceil(log2(30000));
	start_i = 1 << powNum;
	tree_size = start_i * 2;

	sort(map, map + 2 * n);

	int last_x = map[0].x;
	for (int i = 0; i < 2 * n; i++) {
		int cur_x = map[i].x;
		int cur_area = (cur_x - last_x)*tree[1];
		last_x = cur_x;

		ans += cur_area;

		if (map[i].flag == START) {
			update(1, START, map[i].y+1, map[i].y + map[i].h, 1,start_i);
		}
		else if (map[i].flag == END) {
			update(1, END, map[i].y - map[i].h+1, map[i].y, 1,start_i);
		}

	}
	printf("%d\n", ans);
	return 0;
}
