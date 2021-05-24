#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<char> integerSeperation(int n) {
// vector<int> integerSeperation(int n) {

	vector<char> result_char;
	// vector<int> result_int;
	int scale = 1;
	for (; scale * 10<=n; scale *= 10);

	for (int i = n; scale; scale /= 10) {
		int cur = i / scale;
		result_char.push_back(cur + '0');
		// result_int.push_back(cur);
		i = i - scale*cur;
	}

	return result_char;
	// return result_int;
}

vector<int> integerSeperation_2(int n){
	vector<int> res;

	while(n){
		res.push_back(n%10);
		n/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}

int main() {
	int n;  scanf("%d", &n); //10진법 n을 char형(혹은 int형)으로 한 글자씩 자릿수를 분리함.

	vector<char> result=integerSeperation(n);
	// vector<int> result=integerSeperation(n);

	for (char now : result)
		printf("%c ", now);

	return 0;
}
