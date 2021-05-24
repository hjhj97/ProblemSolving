#include<stdio.h>
#include<algorithm>
using namespace std;
struct S {
	int a, b,c;

	const bool operator <(const S&o) {
		if (a != o.a)	return a < o.a;
		else if (b != o.b)	return b < o. b;
		else if (c != o.c)	return c < o.c;
//a,b,c순 정렬
	}
};
int main() {
	S s[4];
	for (int i = 0; i < 4; i++)
		scanf("%d %d %d", &s[i].a, &s[i].b, &s[i].c);

	sort(s, s + 4);

	for (int i = 0; i < 4; i++)
		printf("*%d %d %d\n", s[i].a, s[i].b, s[i].c);

	return 0;
}
