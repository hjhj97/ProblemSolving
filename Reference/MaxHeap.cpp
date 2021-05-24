#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 10000
#define EMPTY -(1<<30)
int heap[SIZE], idx = 0; //heap array is 1 base
void initialize() {
	for (int i = 0; i < SIZE; i++)
		heap[i] = EMPTY;
}
void insert(int val) {
	heap[++idx] = val;

	//going up

	int child = idx;
	int par = child / 2;
	while (par >= 1) {
		if (heap[child] > heap[par])
			swap(heap[child], heap[par]);
		else break;
		child /= 2; par /= 2;
	}
}
int pop() {
	if (idx < 1) {
		printf("NO elements in heap!\n");
		return EMPTY;
	}
	int val = heap[1];
	heap[1] = heap[idx--];

	//going down
	int par = 1;
	while (1) {
		int Lchild = 2 * par, Rchild = 2 * par + 1, child;
		if (Lchild > idx) break;

		if (heap[Rchild] == EMPTY || (heap[par]<heap[Lchild] && heap[Lchild]>heap[Rchild])) {
			child = Lchild;
		}
		else child = Rchild;
		swap(heap[par], heap[child]);

		par = child;
	}
	return val;
}
int main() {
	int n;	scanf("%d", &n);
	initialize();

	for (int i = 0, val, select; i < n; i++) {
		printf("0 for insert, 1 for pop\n");	scanf("%d", &select);

		if (select == 0) {
			scanf("%d", &val);
			insert(val);
		}
		else if (select == 1) {
			printf("%d\n", pop());
		}

		for (int j = 1; j <= idx; j++)
			printf("%d %d\n", j, heap[j]);
	}

	return 0;
}
