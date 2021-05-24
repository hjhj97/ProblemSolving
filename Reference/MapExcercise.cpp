#include<stdio.h>
#include<map>
using namespace std;
int main() {
	map<char, int> m;

	m.insert(make_pair('a', 1)); //이 문장은
	//m['a']=1; 이 문장과 완전히 동일한 기능.
	m.insert(make_pair('b', 2));
	m['c'] = 3;


	printf("%d\n", m['a']); //이 문장은
	//printf("%d\n",m.find('a')->second); 이 문장과 완전히 동일한 기능.

	printf("%d\n", m['b']);
	printf("%d\n", m['c']);
	printf("%d\n", m.count('c')); //'c'라는 키값을 가진 원소가 있으면 1반환, 아니면 0반환
	printf("%d\n", m.count('d'));

	return 0;
}
