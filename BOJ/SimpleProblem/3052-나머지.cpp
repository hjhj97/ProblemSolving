#include<stdio.h>
int main(){
	int mod[42]={0};

	for(int i=0 ; i<10 ; i++){
		int a;	scanf("%d",&a);
		mod[a%42c]++;
	}

	int cnt=0;
	for(int i=0 ; i<42 ; i++){
		if(mod[i]) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}