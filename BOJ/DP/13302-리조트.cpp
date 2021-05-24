#include<stdio.h>
#include<algorithm>
using namespace std;
#define INF 1<<29
#define SIZE 111
int dp[SIZE][SIZE];
int main(){
    int n,m;    scanf("%d %d",&n,&m);

    int arr[SIZE]={0};
    for(int i=0,tmp ; i<m ; i++){
        scanf("%d",&tmp);
        arr[tmp]=1;
    }

    for(int i=0  ; i<=n ; i++)
        for(int j=0 ; j<=n ; j++)
            dp[i][j]=INF;

        dp[0][0]=0;
        for(int i=0 ; i<=n ; i++){
            if(arr[i]){
                for(int j=0 ; j<=n ; j++){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]);
                }
            }

            for(int j=3 ; j<=i ; j++){
                if(dp[i][j]!=INF)
                    dp[i+1][j-3]=min(dp[i+1][j-3],dp[i][j]);
            }

            for(int j=0 ; j<=i ; j++){
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+10000);
                dp[i+3][j+1]=min(dp[i+3][j+1],dp[i][j]+25000);
                dp[i+5][j+2]=min(dp[i+5][j+2],dp[i][j]+37000);
            }
        }

        int ans=INF;
        for(int i=0 ; i<=n ; i++){
            ans=min(ans,dp[n][i]);
        }

        printf("%d\n",ans);
        return 0;
    }