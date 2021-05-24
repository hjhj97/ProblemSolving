#include<stdio.h>
#include<vector>
using namespace std;
#define SIZE 100009
int st[SIZE]={0},size=0;
vector<char> buf;
int main(){
	int n;	scanf("%d",&n);

	int cur=1;
	for(int i=0,tmp ; i<n ;i++){
		scanf("%d",&tmp);

		if(size==0){
			st[size++]=cur++;
			buf.push_back('+');
		}

		while(st[size-1]<tmp){
			st[size++]=cur++;
			buf.push_back('+');
		}

		if(st[size-1]>tmp){
			printf("NO\n");
			return 0;
		}
		else{
			buf.push_back('-');
			size--;
		}
	}

	for(char here:buf)
		printf("%c\n",here);

	return 0;
}