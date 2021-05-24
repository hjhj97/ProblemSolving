#include<stdio.h>
#include<string.h>
int main() {
	char str[55];	scanf("%s", str);
	char rev[55];
	char min=str[0], min2=str[0],min3=str[0];
	int min_pos = 0, min2_pos = 0, min3_pos = 0;
	int len = strlen(str);

	for (int i = 0; str[i] != 0; i++) {
		if (min > str[i]) {
			min = str[i];
			min_pos = i;
		}
		if (min < str[i] && min2 > str[i]) {
			min2 = str[i];
			min2_pos = i;
		}
	}
	for (int i = 0; i <= min_pos; i++) {
		rev[i] = str[min_pos - i];
	}

	for (int i = 0; i <= min2_pos; i++) {
		rev[min_pos + 1 + i] = str[min2_pos - i];
	}

	if (str[min2_pos + 1] > str[len - 1]) {
		for (int i = 0; min2_pos+1+i != len; i++) {
			rev[min2_pos + 1 + i] = str[len - 1 - i];
		}
	}
	else {

	}
	rev[len - 1] = NULL;

	printf("%s", rev);

	//printf("%d %d", min_pos, min2_pos);
	//printf("%c %c", min, min2)

	return 0;
}
