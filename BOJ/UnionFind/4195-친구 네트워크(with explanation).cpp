#include<stdio.h>
#include<map>
#include<string>
using namespace std;
#define SIZE 100100
int p[SIZE], cnt[SIZE];
int find(int a) {
	if (p[a] == -1)
		return a;
	return p[a] = find(p[a]);
}
int merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return cnt[a];
	}
	p[b] = a;
	cnt[a] += cnt[b];
	cnt[b] = 1;
	return cnt[a];
}
int main() {
	int t;	scanf("%d", &t);

	while (t--) {
		int n;	scanf("%d", &n);
		map <string, int> m; //key가 string, value가 int

		for (int i = 0; i <= n; i++) {
			p[i] = -1;
			cnt[i] = 1;
		}
		for (int i = 0, num = 0; i < n; i++) {
			char str1[22], str2[22];
			scanf("%s %s", str1, str2);

			/*
			map의 value값은 현재 자신이 속한 그룹이 몇번째인지를 저장하고있다.
			아래의 if문은 만약 이번에 입력받은 문자열이 이전에 나온 적이 없다면 새롭게 추가해서 본인이 몇번째인지를 저장한다.
			*/
			if (!m.count(str1))
				m[str1] = num++;
			if (!m.count(str2))
				m[str2] = num++;

			printf("%d\n", merge(m[str1], m[str2]));
		}
	}
	return 0;
}
