#include<stdio.h>
#include<set>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
struct Person {
	string str; int a;

	const bool operator <(const Person &o) const {
		return a<o.a;
	}
};

int main() {
	Person person[5];

	person[0].str = "aa", person[0].a = 3;
	person[1].str = "bb", person[1].a = 2;
	person[2].str = "cc", person[2].a = 3;
	person[3].str = "dd", person[3].a = 1;
	person[4].str = "ee", person[4].a = 4;
	//stable_sort preserve order before sorting in case of same key value

	stable_sort(person, person + 5);

	for (int i = 0; i<5; i++) {
		cout << person[i].str << " " << person[i].a << endl;
	}
	return 0;
}