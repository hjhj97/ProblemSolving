#include<stdio.h>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 100009
typedef pair<int,int> pii;
pii arr[SIZE];
int dp[SIZE]={0},idx_arr[SIZE];
int main(){
    int n;  scanf("%d",&n);

    for(int i=0 ; i< n ; i++){
        scanf("%d %d",&arr[i].first,&arr[i].second);
    }

    sort(arr,arr+n);

    int idx=0,start=-1,ans=0;

    for(int i=0 ; i<n ; i++){
        int cur=arr[i].second;

        int l=0,r=idx,mid,tmp=0;

        if(cur>dp[idx]){
            dp[++idx]=cur;
            idx_arr[i]=idx;
        }
        else{ 
            while(r>=l){
                mid=(l+r)/2;

                if(dp[mid]>cur){
                    r=mid-1;
                    tmp=mid;
                }
                else l=mid+1;
            }
            dp[tmp]=cur;
            idx_arr[i]=tmp;
        }

        if(ans<idx_arr[i]){
            ans=idx_arr[i];
            start=i;
        }
    }
    printf("%d\n",n-ans);

    vector<int> v;
    for(int i=n-1 ; i>=0 ; i--){
        if(ans==idx_arr[i]){
            ans--;
        }

        else {
            v.push_back(arr[i].first);
        }
    }

    reverse(v.begin(),v.end());
    for(int here:v)
     printf("%d ",here);


    return 0;
}