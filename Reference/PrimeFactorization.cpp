#include <stdio.h>
#include<map>
#include <math.h>
typedef long long ll;
using namespace std;
map<ll,ll> mp;

int main(){
    ll n;    scanf("%lld", &n);
    for(ll i=2 ; i*i<=n ; i++){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
    }

    if(n>1) mp[n]++;

     for(auto &here:mp)
        printf("%lld %lld\n",here.first,here.second);

 return 0;
}
