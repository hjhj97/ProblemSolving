#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<set>
#include<functional>
#define SIZE 75555
typedef long long ll;
using namespace std;
struct Map {
	int x, y;

	const bool operator <(const Map &o) const {
		return
			(x > o.x) || ((x == o.x) && y < o.y);
		//x는 큰 순, 같다면 y는 작은 순으로 정렬.
	}
};
Map map[SIZE];
ll tree[SIZE * 8];
int idx[SIZE],y_pos[SIZE];
int start_i, tree_size;
ll getCount(int cur_node, int ql, int qr, int cl, int cr) {
	if (ql > cr || qr < cl)
		return 0;
	if (ql <= cl && qr >= cr)
		return tree[cur_node];

	int mid = (cl + cr) / 2;
	return getCount(cur_node * 2, ql, qr, cl, mid) + getCount(cur_node * 2 + 1, ql, qr, mid + 1, cr);
}
void update(int cur_node) { //0 base
	tree[cur_node]++;
	int par = cur_node / 2;

	while (par >= 1) {
		tree[par] = tree[par * 2] + tree[par * 2 + 1];
		par /= 2;
	}
	return;
}
int main() {
	int t;	scanf("%d", &t);

	while (t--) {
		int n;	scanf("%d", &n);
		ll ans = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &map[i].x, &map[i].y);
			y_pos[i] = map[i].y;
		}

		sort(map, map + n);
		sort(y_pos, y_pos + n,greater<int>());

		int powNum = ceil(log2(n));
		start_i = 1 << powNum;
		tree_size = start_i * 2;
		set <int> s;

		int sortedNum = 0;
		for (int i = 0; i < n; i++) { //좌표압축 과정
			if (s.count(y_pos[i]))	continue; //중복체크
			s.insert(y_pos[i]);
			idx[sortedNum++] = y_pos[i];	 //y좌표를 큰 값부터 idx에 채움
			 //좌표압축의 결과 sortedNum은 n보다 작을 수 있음
		}

		for (int i = 0; i < n; i++) {
			int cur = map[i].y, cur_pos = 0;

			int l = 0, r = sortedNum - 1, mid;

			while (r >= l) {
				mid = (l + r) / 2;
				if (idx[mid] == cur)	break;

				else if (idx[mid] > cur)	l = mid + 1;
				else r = mid - 1;
			}
			cur_pos = start_i + mid; //start_i base

			ans += getCount(1, cur_pos - start_i + 1, sortedNum, 1, start_i);
			update(cur_pos);
		}
		printf("%lld\n", ans);
		//0 set
		for (int i = 0; i < tree_size; i++)
			tree[i] = 0;

		for (int i = 0; i < n; i++) {
			map[i].x = 0;	map[i].y = 0;
			idx[i] = 0;	y_pos[i] = 0;
		}
	}
	return 0;
}
