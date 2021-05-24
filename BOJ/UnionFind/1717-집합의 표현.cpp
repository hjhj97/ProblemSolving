#include<stdio.h>
int set[1000010], p[1000010];
int find(int a){ //a노드의 루트를 찾는 연산
	if (p[a] == a) //
		return a;
	return p[a]=find(p[a]);
}
void merge(int a, int b) { //b의 부모가 a가됨->a를 위에,b를 아래에 그림
	a = find(a);
	b = find(b);
	if (a == b) return; //두 노드의 루트가 같으면 그냥 종료
	p[b] = a;
}
int main() {
	int n, m;	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
		p[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;	scanf("%d %d %d", &a, &b, &c);
		if (a == 0)
			merge(b, c);

		else if (a) {
			if (find(b) == find(c))
				printf("YES\n");
			else printf("NO\n");
		}

	}
	return 0;
}
