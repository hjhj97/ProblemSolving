#include<stdio.h>
#include<vector>
#include<queue>
#define SIZE 15
using namespace std;
vector<int> v[SIZE];
vector<int> r[SIZE];
queue<int> q;
int V;
int inD[SIZE], r_inD[SIZE];
char max_num[SIZE], min_num[SIZE];
int main() {
	scanf("%d", &V);

	for (int i = 1; i <= V; i++) {
		char letter;	scanf(" %c", &letter);
		if (letter == '<') {
			v[i + 1].push_back(i);
			r[i].push_back(i + 1);
		}
		else if (letter == '>') {
			v[i].push_back(i + 1);
			r[i + 1].push_back(i);
		}
	}

	for (int i = 1; i <= V+1; i++) {
		q.push(i);
		while (!q.empty()) {
			int cur = q.front(); q.pop();

			for (int next : v[cur]) {
					q.push(next);
					inD[next]++;
			}
		}
	}

	for (int i = 1; i <= V+1; i++) {
		q.push(i);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int next : r[cur]) {
				q.push(next);
				r_inD[next]++;
			}
		}
	}

	queue<int> dq;

	bool used[SIZE] = { false };
	for (int i = 1; i <= V + 1; i++) {
		for (int j = 9; j >= 0; j--) {
			if (!used[j]) {
				max_num[i - 1] = '0' + j - inD[i];
				used[j - inD[i]] = true;
				dq.push(i);
				while (!dq.empty()) {
					int cur = dq.front();	dq.pop();

					for (int next : v[cur]) {
						dq.push(next);
						inD[next]--;
					}
				}
				break;
			}
		}
	}

	bool used2[SIZE] = { false };
	for (int i = 1; i <= V + 1; i++) {
		for (int j = 0; j <= 9; j++) {
			if (!used2[j]) {
				min_num[i - 1] = '0' + j + r_inD[i];
				used2[j + r_inD[i]] = true;
				dq.push(i);
				while (!dq.empty()) {
					int cur = dq.front();	dq.pop();

					for (int next : r[cur]) {
						dq.push(next);
						r_inD[next]--;
					}
				}
				break;
			}
		}
	}
	max_num[V + 1] = 0;
	min_num[V + 1] = 0;
	printf("%s\n%s\n", max_num, min_num);


	return 0;
}
/*
4
> < < >
->96785 10243
4
< > > <
4
> > > <
*/
