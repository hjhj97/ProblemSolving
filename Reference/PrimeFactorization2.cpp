#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
const int SCALE = 5000009;
int minfac[SCALE]={0};

int main(){
    int n;  scanf("%d",&n);
    minfac[0]=minfac[1]=-1;
    
    for(int i=2 ; i<SCALE ; i++)
        minfac[i]=i;

    for(int i=2 ; i*i<SCALE ; i++){
        for(int j=i*i ; j<SCALE ; j+=i){
            if(minfac[j]==j)
                minfac[j]=i;
        }
    }

    while(n--){
        int inp;    scanf("%d",&inp);
        vector<int> ans;
        while(inp>1){
            ans.push_back(minfac[inp]);
            inp /= minfac[inp];
        }
        sort(ans.begin(),ans.end());
        for(int here: ans) printf("%d ",here);
        printf("\n");
    }

    return 0;
}
