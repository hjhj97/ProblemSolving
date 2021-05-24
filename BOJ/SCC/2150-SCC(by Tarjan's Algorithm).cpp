//SCC by Tarjan's Algorithm
#include<stdio.h>
#include<stack>
#include<vector>
#include<algorithm>
#define SIZE 10010
using namespace std;
vector <int> v[SIZE];
vector<int> scc[SIZE];
vector<int> st;
bool finished[SIZE] = { false };
int cnt = 1, idx[SIZE], scc_cnt = 0;
int min(int a, int b) {
    return a > b ? b : a;
}
int dfs(int cur) {
    idx[cur] = cnt++; //각 vertex마다 방문한 순서대로 idx배열에 값을 넣음.
    st.push_back(cur);
    int val=idx[cur];

    for (int next : v[cur]) {
        if (idx[next] == 0) { //아직 방문하지 않은 점을 dfs로 계속 탐색.
            val=min(val,dfs(next));
        }
        else if (!finished[next])
            val = min(val, idx[next]);
    }

    if (idx[cur] == val) { //scc로 묶을 수 있는 조건 만족시
        while (1) {
            int top=st.back();  st.pop_back();
            scc[scc_cnt].push_back(top);
            finished[top]=true;

            if(top==cur) break;
        }
        sort(scc[scc_cnt].begin(), scc[scc_cnt].end());
        scc_cnt++;
    }
    return val;
}
int main() {
    int V, e;   scanf("%d %d", &V, &e);

    for (int i = 1; i <= e; i++) {
        int a, b;    scanf("%d %d", &a, &b);
        v[a].push_back(b);
    }
    for (int i = 1; i <= V; i++) {
        if (idx[i] == 0)    dfs(i);
    }

    sort(scc, scc + scc_cnt);
    printf("%d\n", scc_cnt);
    for (int i = 0; i < scc_cnt; i++) {
        for (int j = 0; j < scc[i].size(); j++) {
            printf("%d ", scc[i][j]);
        }
        printf("-1\n");
    }

    return 0;
}