#include<stdio.h>
#include<algorithm>
#include<set>
#include<string>
#include<vector>
using namespace std;
#define SIZE 20010
bool cmp(string &s1, string &s2) {
	if (s1.size() == s2.size()) {
		return s1 < s2;
	}
	return s1.size() < s2.size();
}
int main() {
	set <string> s;
	vector<string> v;
	int n;	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char str[55];
		scanf("%s", str);
		if (!s.count(str)) {
			s.insert(str);
			v.push_back(str);
		}
	}
	sort(v.begin(), v.end(),cmp);

	for (string s : v) {
		printf("%s\n", s.c_str());
	}
	return 0;
}
