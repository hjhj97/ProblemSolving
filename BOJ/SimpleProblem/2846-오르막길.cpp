#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 1001
int h[SIZE],idx[SIZE];
int main(){
	int n;	scanf("%d",&n);

	for(int i=0 ; i<n ; i++){
		scanf("%d",&h[i]);
	}
	int cnt=1; idx[0]=cnt;
	for(int i=1 ; i<n ; i++){
		if(h[i-1]<h[i]){
			idx[i]=idx[i-1];
		}
		else idx[i]=++cnt;
	}
	int ans=0;
	for(int i=0,cur_idx=1,first_idx=0 ; i<n ; i++){
		if(cur_idx!=idx[i]){
			ans=max(ans,h[i-1]-h[first_idx]);
			cur_idx=idx[i];
			first_idx=i;
		}
		else if(i==n-1){
			ans=max(ans,h[i]-h[first_idx]);
		}
	}

	printf("%d\n",ans);
	return 0;
}