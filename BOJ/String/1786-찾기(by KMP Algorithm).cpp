#include<stdio.h>
#include<vector>
#define SIZE 1000009
using namespace std;
char txt[SIZE], ptn[SIZE];
int fail[SIZE];
int P = 0, T = 0;
vector<int> ans;
int main() {
	fgets(txt, SIZE, stdin);
	fgets(ptn, SIZE, stdin);

	for (; txt[T]; T++);
	txt[--T] = 0;
	for (; ptn[P]; P++);
	ptn[--P] = 0;

	for (int i = 1, j = 0; i < P; i++) {
		while (j > 0 && ptn[i] != ptn[j]) j = fail[j - 1];
		if (ptn[i] == ptn[j]) fail[i] = ++j;
	}

	// 1-base KMP
	// for(int i=2,j=0 ; i<= n ;i++){
 //        while(j && str[i]!=str[j+1]) j=fail[j];
 //        if(str[i]==str[j+1]) fail[i] = ++j;
 //    }

	for (int i = 0, j = 0; i < T; i++) {
		while (j > 0 && txt[i] != ptn[j]) j = fail[j - 1];
		if (txt[i] == ptn[j]) {
			if (j == P - 1) {
				ans.push_back(i - P + 2);
				j = fail[j];
			}
			else j++;
		}

	}
	printf("%d\n", ans.size());

	for (int i : ans)
		printf("%d ", i);


	return 0;
}
