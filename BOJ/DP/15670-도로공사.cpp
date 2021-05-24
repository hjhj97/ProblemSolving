#include<stdio.h>
#define SIZE 100009
#define INF 1<<30

int arr[SIZE],sum[SIZE];
int main(){
    int n,m;    scanf("%d %d",&n,&m);

    arr[0]=0,sum[0]=1;
    arr[n+1]=INF;

    for(int i=1 ; i<=n ; i++){
        scanf("%d",&arr[i]);
        if(arr[i]>arr[i-1])
            sum[i]=sum[i-1];
        else sum[i]=sum[i-1]+1;
    }
    sum[n+1]=sum[n];
    
    while(m--){
        int l,r;    scanf("%d %d",&l,&r);

        int ans=0,len=r-l+1;

        ans+=len-(sum[r]-sum[l]);

        if(n==1) ans=1;
 
        else if(l==r){ 
            ans=sum[n];
        }
        else if(l==1 && r==n){
            ;
        }

        else{
         if(arr[l-1] > arr[r]) ans++;
         if(arr[r+1] < arr[l]) ans++;
         ans+=sum[l-1]-sum[0]+sum[n]-sum[r+1];
        }
     
     printf("%d\n",ans);
 }

 return 0;
}