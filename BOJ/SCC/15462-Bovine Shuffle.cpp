//SCC by Tarjan's Algorithm
#include<stdio.h>
#include<stack>
#include<vector>
#include<algorithm>
#define SIZE 100010
using namespace std;
vector <int> v[SIZE];
vector<int> scc[SIZE];
stack<int> s;
bool visited[SIZE] = { false };
int cnt = 1, idx[SIZE], low[SIZE], scc_cnt = 0,ans=0;
int min(int a, int b) {
	return a > b ? b : a;
}
void dfs(int cur) {
	low[cur] = cnt;	idx[cur] = cnt++; //각 vertex마다 방문한 순서대로 idx배열에 값을 넣음.
	s.push(cur);
	visited[cur] = true;
	for (int next : v[cur]) {

		if (idx[next] == 0) { //아직 방문하지 않은 점을 dfs로 계속 탐색.
			dfs(next);
			low[cur] = min(low[cur], low[next]); //low배열을 각 vertex의 origin중에서 가장 작은 값을 저장함.
		}
		else if (visited[next]) //방문한 점을 찾으면 -> dfs탐색 멈추고 backtrack시작하면서 low배열 갱신해 나감.
			low[cur] = min(low[cur], low[next]);
	}

	bool flag=false;
	if (idx[cur] == low[cur]) { //scc로 묶을 수 있는 조건 만족시
		if(cur!=s.top())
			flag=true;
		
		while (1) {
			int top = s.top();	s.pop();
			scc[scc_cnt].push_back(top);
			visited[top] = false;

			if(flag) ans++;
			if (idx[top] == low[top]) {
				break;
			}
		}
		

		// sort(scc[scc_cnt].begin(), scc[scc_cnt].end());
		// scc_cnt++;
	}
}
int main() {
	int V;	scanf("%d", &V);

	for(int i=1 ; i<=V ; i++){
		int dest;	scanf("%d",&dest);
		if(i==dest) ans++;
		v[i].push_back(dest);
	}
	

	for (int i = 1; i <= V; i++) {
		if (idx[i] == 0)	dfs(i);
	}

	printf("%d\n",ans);

	return 0;
}
