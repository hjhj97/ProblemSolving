#include<stdio.h>
#include<vector>
using namespace std;
vector<int> integerSeperation(int n) { //Integer Seperation 함수
	vector<int> result_int;
	int scale = 1;
	for (; scale * 10<n; scale *= 10);

	for (int i = n; scale; scale /= 10) {
		int cur = i / scale;
		result_int.push_back(cur);
		i = i - scale*cur;
	}

	return result_int;
}
vector<int> conversion(int n, int digit) { //10진법의 수 n을 digit진법으로 변환하는 함수
	vector<int> result;
	for (int i = n; i>0; i /= digit) {
		result.push_back(i%digit);
	}
	reverse(result.begin(), result.end());

	return result;
}

int main() {
	int from, n, to;  scanf("%d %d %d", &from, &n, &to); //from진법의 수 n을 to진법으로 변환함
	vector<int> &result = integerSeperation(n);

	int decimal_n = 0, digit = 1;

	for (int i = result.size() - 1; i >= 0; i--) {
		decimal_n += result[i] * digit;
		digit *= from;
	}
	vector<int> &result2 = conversion(decimal_n, to);

	printf("%d진법의 수 %d을 %d진법으로 변환한 결과 : ",from,n,to);
	for (int here : result2)
		printf("%d", here);

	return 0;
}
