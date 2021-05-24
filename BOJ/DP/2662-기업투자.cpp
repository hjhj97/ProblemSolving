#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 309

int dp[SIZE][22],benefit[SIZE][22],add[SIZE][22];
int main(){
    int n,m;    scanf("%d %d",&n,&m);


    for(int i=0 ; i<n ; i++){
        int cur;    scanf("%d",&cur);
        for(int j=1 ; j<=m ; j++){
            scanf("%d",&benefit[cur][j]);
        }
    }

    for(int i=0 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            for(int k=0 ; k<=i ; k++){
                int last=dp[i][j],now=dp[i-k][j-1]+benefit[k][j];
                if(last<now){
                    dp[i][j]=now;
                    add[i][j]=k;
                }
            }
        }
    }

    int total=0;

    for(int i=0 ; i<=n ; i++)
        total=max(total,dp[i][m]);

    vector<int> v;
    int tgt=total;

    for(int i=m ; i>=1 ; i--){
        for(int j=n ; j>=0 ; j--){
            if(tgt==dp[j][i]){
                int idx=add[j][i];
                tgt-=benefit[idx][i];
                v.push_back(idx);
                break;
            }
        }
    }

    reverse(v.begin(),v.end());
   
    printf("%d\n",total);
    for(int here:v) 
        printf("%d ",here);

    return 0;
}