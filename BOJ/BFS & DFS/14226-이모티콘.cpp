#include<stdio.h>
#include<queue>
using namespace std;
struct Mark {
	int num, time,pre_paste;

	Mark(){}
	Mark(int _num, int _time,int _pre_paste) {
		num = _num;
		time = _time;
		pre_paste = _pre_paste;
	};
};
bool check[1200][1200] = { false };
int main() {
	int s;	scanf("%d", &s);

	queue<Mark> q;

	q.push(Mark(1, 0,0));

	while (1) {
		Mark cur = q.front();	 q.pop();
		check[cur.num][cur.pre_paste] = true;
		//printf("%d %d\n", cur.num, cur.time);

		if (cur.num == s) {
			printf("%d\n", cur.time);
			return 0;
		}

		if(!check[cur.num][cur.num])
			q.push(Mark(cur.num, cur.time + 1, cur.num)); //복사

		if (cur.num + cur.pre_paste <= 1010) //붙여넣기
			if(!check[cur.num+cur.pre_paste][cur.pre_paste])
				if (cur.pre_paste >= 1)
					q.push(Mark(cur.num + cur.pre_paste, cur.time + 1, cur.pre_paste));

		if(!check[cur.num-1][cur.pre_paste])
			if (cur.num >= 1) //빼기
				q.push(Mark(cur.num - 1, cur.time + 1, cur.pre_paste));
	}
}
