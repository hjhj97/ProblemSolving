#include<stdio.h>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
	return (a<b); //오름차순으로 정렬됨
	//return !(a<b) 라고 하면 내림차순으로 정렬됨.
}
int main() {
	int num[5] = { 3,2,5,1,4 };

	sort(num, num + 5, cmp);

	for (int i = 0; i < 5; i++)
		printf("%d ", num[i]);

	return 0;
}
