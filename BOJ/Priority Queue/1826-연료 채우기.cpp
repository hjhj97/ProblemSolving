#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
#define SIZE 10009
struct Oil{
	int d,c;

	Oil(){}
	Oil(int _d,int _c){
		d=_d;
		c=_c;
	}
	const bool operator<(const Oil &o) const{
		return d<o.d;
	}
};
priority_queue<int> pq;
int n;
Oil o[SIZE];
int main(){
	scanf("%d",&n);

	for(int i=0 ; i<n ;i++){
		int a,b;	scanf("%d %d",&a,&b);
		o[i]=Oil(a,b);
	}

	int dest,init;	scanf("%d %d",&dest,&init);

	sort(o,o+n);

	int cur=init,ans=0,idx=0;

	while(cur<dest){
		for( ; cur >= o[idx].d ; idx++){
			pq.push(o[idx].c);
		}	

		while(cur < o[idx].d && cur<dest){
			int top=pq.top();	pq.pop();
			cur+=top;
			ans++;

			if(pq.size()==0 && cur<o[idx].d){
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}