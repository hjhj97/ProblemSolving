#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){
	int t;	scanf("%d",&t);

	while(t--){
		int n;	scanf("%d",&n);
		vector<int> v;
		for(int i=0,cur ; i<n ; i++){
			scanf("%d",&cur);
			v.push_back(cur);
		}

		sort(v.begin(),v.end());
		int m;	scanf("%d",&m);
		while(m--){
			int q;	scanf("%d",&q);
			int l=0,r=v.size();

			int ans=0;
			while(r>=l){
				int mid=(l+r)/2;

				if(v[mid]==q){
					ans=1;
					break;
				}

				else if(v[mid]>q){
					r=mid-1;
				}
				else l=mid+1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}