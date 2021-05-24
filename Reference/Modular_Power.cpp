typedef long long ll;
ll my_pow(ll n,ll k){
    ll result=1;
    while(k){
        if(k&1) //k값이 홀수일 때만 계산
            result=(result*n)%MOD;
        k/=2;
        n=(n*n)%mod;
    }
    return result;
}
int main(){
 
    int ans=0;
    ans-=my_pow(N,K);
 
    ans=ans+MOD;
    ans=ans%MOD;
    
    .
    .
    .
}
