#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define SIZE 50
typedef pair<int, int> Cord;
vector<Cord> chick;
vector<Cord> home;
int n, m,size_of_chick,size_of_home,pick[13],ans=1<<30;
int map[SIZE][SIZE];
int fAbs(int a) {
	return a > 0 ? a : -a;
}
int chick_dist() {
	int sum = 0, min_dist[SIZE * 2] = { 0 };

	for (int i = 0; i < size_of_home; i++) {
		min_dist[i] = 1 << 30;
		for (int j = 0; j < m ; j++) {
			int dist =
				fAbs(home[i].first - chick[pick[j]].first) +
				fAbs(home[i].second - chick[pick[j]].second);

			min_dist[i] = min(min_dist[i], dist);
		}
		sum += min_dist[i];
	}
	return sum;
}
void dfs(int cnt,int last) {
	if (cnt == m) {
		ans = min(ans, chick_dist());

		return;
	}
	for (int i = last + 1; i < size_of_chick; i++) {

		pick[cnt] = i;
		dfs(cnt + 1, i);
	}
	return;
}
int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				home.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2) {
				chick.push_back(make_pair(i, j));
			}
		}
	}
	size_of_chick = chick.size();
	size_of_home = home.size();

	dfs(0, -1);
	printf("%d\n", ans);

	return 0;
}
