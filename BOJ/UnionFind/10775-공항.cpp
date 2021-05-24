#include<stdio.h>
#define SIZE 100010
int g, plane, ans = 0;
int p[SIZE];
int find(int a) {
	if (p[a] == -1)
		return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)	return;
	p[b] = a;
}
int main() {
	scanf("%d %d", &g, &plane);

	for (int i = 0; i <= g; i++)
		p[i] = -1;

	for (int i = 0, a; i < plane; i++) {
		scanf("%d", &a);
		if (find(a) == 0) {
			break;
		}
		merge(find(a)-1,a);
		ans++;
	}

	printf("%d\n", ans);
	return 0;
}
