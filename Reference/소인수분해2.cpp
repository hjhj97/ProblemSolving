#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<functional>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stdlib.h>
#include<stack>
using namespace std;
const int SIZE=5000009;
int minfac[SIZE]={0};

int main(){
    int n;  scanf("%d",&n);
    minfac[0]=minfac[1]=-1;
    
    for(int i=2 ; i<SIZE ; i++)
        minfac[i]=i;

    for(int i=2 ; i*i<SIZE ; i++){
        for(int j=i*i ; j<SIZE ; j+=i){
            if(minfac[j]==j)
                minfac[j]=i;
        }
    }

    while(n--){
        int inp;    scanf("%d",&inp);
        vector<int> ans;
        while(inp>1){
            ans.push_back(minfac[inp]);
            inp/=minfac[inp];
        }
        sort(ans.begin(),ans.end());
        for(int here: ans) printf("%d ",here);
        printf("\n");
    }

    return 0;
}
