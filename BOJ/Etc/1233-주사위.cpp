#include<stdio.h>
int count[20 + 20 + 40 + 10];
int main() {
	int s1, s2, s3;	scanf("%d %d %d", &s1, &s2, &s3);
	int sum_max = 0; //
	int count_max = 0; //빈도수 최대

	for (int i = 1; i <= s1; i++)
		for (int j = 1; j <= s2; j++)
			for (int k = 1; k <= s3; k++) {
				count[i+j+k]++;
			}

	for (int i = 1; i <= s1 + s2 + s3; i++) {
		if (count_max < count[i]) {
			count_max = count[i];
			sum_max = i;
		}
	}

	printf("%d\n", sum_max);

	return 0;
}
