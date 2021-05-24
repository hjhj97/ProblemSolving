#include<stdio.h>
int main() {
	int n;	scanf("%d", &n);
	char letter[100];

	for (int i = 0; i < 5; i++)
		scanf(" %c", &letter[i]); //문자형이 공백으로 구분되어서 들어올때
						-> %c앞에 공백 한칸

	for (int i = 0; i < 5; i++)
		printf("%c ", letter[i]);

	return 0;
}
---------------------------------------------------------------------------------------------------
#include<stdio.h>
int main() {
	int n;	scanf("%d ", &n); //문자형이 공백없이 들어올때
	char letter[100];		->%d 뒤에 공백 한칸

	for (int i = 0; i < 5; i++)
		scanf("%c", &letter[i]);


	for (int i = 0; i < 5; i++)
		printf("%c ", letter[i]);

	return 0;
}
