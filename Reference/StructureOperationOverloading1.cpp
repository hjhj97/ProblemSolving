#include<stdio.h>
#include<algorithm>
using namespace std;
struct Set {
	int a, b;
	Set(){}
	Set(int a, int b) :a(a), b(b) {};

	const bool operator <(const Set&o)const {
		return a < o.a; //a기준으로 작은수부터 정렬(오름차순)
	}
};
Set set[3];
int main() {
	set[0].a = 1, set[0].b = 100;
	set[1].a = 10, set[1].b = 10;
	set[2].a = 100, set[2].b = 1;

	sort(set, set + 3);

	for (int i = 0; i < 3; i++)
		printf("%d %d\n",set[i].a, set[i].b);

	return 0;
}
