#include<stdio.h>

int main(){
    int n,s;    scanf("%d %d",&n,&s);

    int arr[21],ans=0;
    for(int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }

    for(int i=1 ; i<(1<<n) ; i++){
        int sum=0;
        for(int j=0 ; j<n ; j++){
            if(i&(1<<j)){
                sum+=arr[j];
            }
        }
        if(sum==s) ans++;
    }
    printf("%d\n",ans);
    return 0;
}