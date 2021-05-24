#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
#define SIZE 500100
using namespace std;
struct  Route{
	int pos, cash;

	Route(int _pos,int _cash) {
		pos = _pos;
		cash = _cash;
	}
};
vector <int> v[SIZE];
vector<int> scc[SIZE];
vector<int> scc_adj[SIZE];
stack<int> s;
int idx[SIZE], low[SIZE],street_cash[SIZE],scc_idx[SIZE];
int atm[SIZE],inD[SIZE],street_sum_cash[SIZE];
bool visited[SIZE] = { false }, isRstr[SIZE] = { false };
int cnt = 1, scc_cnt = 0,max_cash=0;
int fMin(int a, int b) {
	return a > b ? b : a;
}
int fMax(int a, int b) {
	return a > b ? a : b;
}
void Dfs(int cur) {
	idx[cur] = low[cur] = cnt++;
	visited[cur] = true;
	s.push(cur);

	for (int next : v[cur]) {
		if (idx[next] == 0) {
			Dfs(next);
			low[cur] = fMin(low[cur], low[next]);
		}
		else if (visited[next]) {
			low[cur] = fMin(low[cur], low[next]);
		}
	}

	if (idx[cur] == low[cur]) {
		while (1) {
			int top = s.top();	s.pop();
			visited[top] = false;
			scc[scc_cnt].push_back(top);
			scc_idx[top] = scc_cnt;
			street_cash[scc_cnt] += atm[top];

			if (idx[top]==low[top])	break;
		}
		scc_cnt++;
	}
}
int main() {
	int V, e;	scanf("%d %d", &V, &e);

	for (int i = 0, a, b; i < e; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
	}

	for (int i = 1; i <= V; i++)
		scanf("%d", &atm[i]);

	int start, rstrNum;	scanf("%d %d", &start, &rstrNum);

	for (int i = 1; i <= V; i++)
		if (idx[i] == 0)	Dfs(i);

	for (int i = 0, a; i < rstrNum; i++) {
		scanf("%d", &a);
		isRstr[scc_idx[a]] = true;
	}

	for(int i=1 ; i<=V ; i++)
		for (int j : v[i]) {
			if (scc_idx[i] == scc_idx[j])	continue;
			scc_adj[scc_idx[i]].push_back(scc_idx[j]);
			inD[scc_idx[j]]++;
		}

	start = scc_idx[start];
	inD[start]++;

	queue<int> q;
	for (int i = 0; i < scc_cnt; i++)
		if (inD[i] == 0)	q.push(i);

	while (!q.empty()) {
		int cur = q.front();	q.pop();

		for (int next : scc_adj[cur]) {
			if (--inD[next] == 0)
				q.push(next);
		}
	}

	queue<Route> Rq;
	Rq.push(Route(start,street_cash[start]));
	while (!Rq.empty()) {
		Route cur = Rq.front();	Rq.pop();

		if (isRstr[cur.pos])
			max_cash = fMax(max_cash, street_sum_cash[cur.pos]);

		for (int next : scc_adj[cur.pos]) {
			street_sum_cash[next] = fMax(street_sum_cash[next],
										cur.cash + street_cash[next]);
			if (--inD[next] == 0)
				Rq.push(Route(next,street_sum_cash[next]));
		}
	}

	printf("%d\n", max_cash);
	return 0;
}
