#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;	scanf("%d",&n);

	while(n--){
		string str;
		cin>>str;

		int len=str.length();
		int op=0,cl=0,cur=0;
		for(int i=0 ; str[i] ; i++){
			cur+=(str[i]=='(')?1:-1;
			cl=max(cl,-cur);
		}
		cur=0;
		for(int i=len-1 ; i>=0 ; i--){
			cur+=(str[i]==')')?1:-1;
			op=max(op,-cur);
		}

		if(op==0 && cl==0){
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}