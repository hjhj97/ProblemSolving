#include<stdio.h>
#include<algorithm>
using namespace std;
struct Person {
	int age, num;

	Person() {}
	Person(int _age, int _num) {
		age = _age;
		num = _num;
	}

	const bool operator < (const Person&o) const {
		return (age < o.age) || (age==o.age && num<o.num); //age가 같을 경우, num이 작은 순으로 정렬
	}
};
int main() {
	Person person[4];

	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &person[i].age, &person[i].num);
	}

	sort(person,person+4);

	for (Person i : person)
		printf("%d %d\n", i.age, i.num);

	return 0;
}
/*
2 3
2 1
1 2
3 4

*/
