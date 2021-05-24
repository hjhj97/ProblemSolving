#include<stdio.h>
struct Count {
	int zero, one;

	const Count operator +(const Count &o) {
		return{ zero + o.zero,one + o.one };
	}
};
Count count[45];
int count0, count1;
Count fib(int cur) {
	if (count[cur].zero + count[cur].one != 0) {
		count0 += count[cur].zero;
		count1 += count[cur].one;
		return count[cur];
	}
	//if (cur == 0)	return{ 1,0 };

	count[cur] = fib(cur - 1) + fib(cur - 2);
	return count[cur];
}
int main() {
	int t;	scanf("%d", &t);
	count[0].zero = 1;	count[0].one = 0;
	count[1].zero = 0;	count[1].one = 1;
	while (t--) {
		int n;	scanf("%d", &n);
		fib(n);

		printf("%d %d\n", count0, count1);
		count0 = 0;	count1 = 0;
	}
	return 0;
}
