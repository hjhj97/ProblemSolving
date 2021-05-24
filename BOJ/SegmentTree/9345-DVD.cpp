#include<stdio.h>
#include<math.h>
#define SIZE 100100
int mtree[SIZE * 8],Mtree[SIZE*8],shelf[SIZE];
int start_i, tree_size;

int fMin(int a, int b) {
	return a > b ? b : a;
}
int fMax(int a, int b) {
	return a > b ? a : b;
}
int make_mtree(int cur_node) {
	if (cur_node >= start_i)
		return mtree[cur_node];

	mtree[cur_node] = fMin(make_mtree(cur_node * 2), make_mtree(cur_node * 2 + 1));

	return mtree[cur_node];
}
int make_Mtree(int cur_node) {
	if (cur_node >= start_i)
		return Mtree[cur_node];

	Mtree[cur_node] = fMax(make_Mtree(cur_node * 2), make_Mtree(cur_node * 2 + 1));

	return Mtree[cur_node];
}
int getMin(int cur_node,int ql,int qr,int cl,int cr) {
	if (ql > cr || qr < cl)
		return SIZE+1;

	if (ql <= cl && qr >= cr)
		return mtree[cur_node];

	int mid = (cl + cr) / 2;
	return fMin(getMin(cur_node * 2, ql, qr, cl, mid), getMin(cur_node * 2 + 1, ql, qr, mid + 1,cr));

}
int getMax(int cur_node,int ql,int qr,int cl,int cr) {
	if (ql > cr || qr < cl)
		return -1;

	if (ql <= cl && qr >= cr)
		return Mtree[cur_node];

	int mid=(cl + cr) / 2;
	return fMax(getMax(cur_node * 2, ql, qr, cl, mid), getMax(cur_node * 2 + 1, ql, qr, mid + 1, cr));

}
void mUpdate(int b,int c) {
	mtree[b + start_i] = shelf[c];
	mtree[c + start_i] = shelf[b];

	int b_par = (b + start_i) / 2;
	int c_par = (c + start_i) / 2;
	while (b_par >= 1) {
		mtree[b_par] = fMin(mtree[b_par * 2], mtree[b_par * 2 + 1]);
		b_par /= 2;
	}

	while (c_par >= 1) {
		mtree[c_par] = fMin(mtree[c_par * 2], mtree[c_par * 2 + 1]);
		c_par /= 2;
	}

}
void MUpdate(int b,int c) {
	Mtree[b + start_i] = shelf[c];
	Mtree[c + start_i] = shelf[b];

	int b_par = (b + start_i) / 2;
	int c_par = (c + start_i) / 2;
	while (b_par >= 1) {
		Mtree[b_par] =fMax(Mtree[b_par * 2],Mtree[b_par * 2 + 1]);
		b_par /= 2;
	}

	while (c_par >= 1) {
		Mtree[c_par] = fMax(Mtree[c_par * 2], Mtree[c_par * 2 + 1]);
		c_par /= 2;
	}

}
int main() {
	int t;	scanf("%d", &t);

	while (t--) {
		int n, k;	scanf("%d %d", &n, &k);

		int powNum = ceil(log2(n));
		start_i = 1 << powNum;
		tree_size = start_i * 2;

		for (int i = 0; i < n; i++) {
			mtree[i + start_i] = i;
			Mtree[i + start_i] = i;
			shelf[i] = i;
		}
		mtree[n + start_i] = SIZE + 1; //기본값 0으로 잘못 초기화 되는 것 방지

		make_mtree(1);	make_Mtree(1);

		while (k--) {
			int a, b, c;	scanf("%d %d %d", &a, &b, &c);

			if (a == 0) {
				mUpdate(b,c);
				MUpdate(b,c);

				int dvd_on_b_shelf = shelf[b];
				int dvd_on_c_shelf = shelf[c];

				shelf[b] = dvd_on_c_shelf;
				shelf[c] = dvd_on_b_shelf;
			}
			else if (a == 1) {
				int minNum = getMin(1,b+1,c+1,1,start_i);
				int maxNum = getMax(1,b+1,c+1,1,start_i);

				if (minNum == b && maxNum == c)	printf("YES\n");
				else printf("NO\n");
			}
		}
		//0 set
		for (int i = 0; i < tree_size; i++) {
			mtree[i] = 0;
			Mtree[i] = 0;
		}
		for (int i = 0; i <= n; i++)
			shelf[i] = 0;
	}
	return 0;
}
