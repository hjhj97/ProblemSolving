#include<stdio.h>
#define SIZE 300010
int n, l;
int p[SIZE];
bool used[SIZE] = { false };
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
	scanf("%d %d", &n, &l);

	for (int i = 1; i <= l; i++)
		p[i] = -1;

	for (int i = 0, a,b; i < n; i++) {
		scanf("%d %d", &a, &b);

		int aa = find(a);
		int bb = find(b);
		if (!used[aa]) {

			used[aa] = true;
			printf("LADICA\n");
		}

		else if (!used[bb]) {

			used[bb] = true;
			printf("LADICA\n");
		}
		else{

			printf("SMECE\n");
		}

		merge(b,a); //b를 루트, a를 자식으로 merge
	}

	return 0;
}
