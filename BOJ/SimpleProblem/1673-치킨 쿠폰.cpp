#include<stdio.h>
int main(){
	int n,k;
	while(scanf("%d %d",&n,&k)!=EOF){
		int ans=0,coupon=n,stamp=0;
		// ans+=n;
		while(coupon){
			ans+=coupon;
			stamp+=(coupon%k);
			coupon/=k;
			coupon+=(stamp/k);
			stamp=stamp-k*(stamp/k);
		}

		printf("%d\n",ans);
	}
	return 0;
}