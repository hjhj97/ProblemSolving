#include<stdio.h>
#define SIZE 100100
int heap[SIZE], size = 0;
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void ins_heap(int val) { //heap삽입함수
	size++;
	int a = size; //노드 맨 마지막(배열의 맨 끝)에 저장한다.
	heap[a] = val;

	while (a != 1 && (heap[a]<heap[a / 2])) { //새로 들어온 노드를 부모 노드와 비교해서 값이 더 작으면 swap한다.
		swap(&heap[a], &heap[a / 2]);
		a /= 2;
	}
}
void pop(void) { //pop함수
	if (size == 0) {
		printf("0\n");
		return;
	}
	printf("%d\n", heap[1]);
	heap[1] = heap[size];
	size--;

	//새로운 root의 노드를 찾아가야함
	int child;

	for (int par = 1; par*2 <= size; par=child) { //루트노드와 그의 두 자식중에서 (최소힙이라면) 작은 값하고만 비교하고 필요하면swap한다.
		if (heap[2 * par] < heap[2 * par + 1]||size<2*par+1)
			child = 2 * par;

		else child = 2 * par+1;

		if (heap[par] > heap[child])
			swap(&heap[par], &heap[child]);

		else break;
	}
}

int main() {
	int n, x, count = 0; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (x == 0) {
			pop();
			continue;
		}

		ins_heap(x);

	}

	return 0;
}

/*
20
1 3 5 4 2 6 7 10 9 8
0 0 0 0 0 0 0 0 0 0 0
*/
