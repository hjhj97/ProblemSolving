#include<stdio.h>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
priority_queue <int,vector<int>,greater<int>> mpq;
priority_queue <int> Mpq;
int main() {
	int n;	scanf("%d", &n);

	while (n--) {
		int num;	scanf("%d", &num);

		if (Mpq.size() > mpq.size())
			mpq.push(num);

		else Mpq.push(num);

		if (mpq.size()>=1 && Mpq.top() > mpq.top()) {
			int M = Mpq.top();	Mpq.pop();
			int m = mpq.top();	mpq.pop();

			Mpq.push(m);	mpq.push(M);
		}
		printf("%d\n", Mpq.top());
	}
	return 0;
}
