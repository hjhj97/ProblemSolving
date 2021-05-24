#include<stdio.h>
#include<math.h>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii; //first=value, second=count


vector<int> int_seperation(int num){
	vector<int> result;
	int scale=1;

	for(;scale*10 <=num ; scale*=10);

	while(scale){
		int cur=num/scale;
		result.push_back(cur);
		num=num-cur*scale;
		scale/=10;
	}

	return result;
}

int main(){

	int t;	scanf("%d",&t);

	bool prime[10009]={true};
	for(int i=1 ; i<=10000 ; i++) prime[i]=true;
	
	for(int i=2 ; i<10000 ; i++){
		for(int j=2 ; i*j<10000 ; j++){
			prime[i*j]=false;
		}
	}

	while(t--){
		int a,b;	scanf("%d %d",&a,&b);
		bool visited[10009]={false};

		queue<pii> q;
		q.push(make_pair(a,0));

		int ans=-1;
		while(!q.empty()){
			int cur_val=q.front().first;
			int cur_cnt=q.front().second;

			visited[cur_val]=true;
			if(cur_val==b){
				ans=cur_cnt;
				break;
			}

			q.pop();
			visited[cur_val]=true;
			vector<int> cur_sep=int_seperation(cur_val);

			for(int k=0 ; k<4 ; k++){
				for(int i=0 ; i<=9 ; i++){
					if(cur_sep[k]==i) continue;
					int merge=cur_val-cur_sep[k]*pow(10,3-k)+i*pow(10,3-k);
					if(merge<1000) continue;
					if(!visited[merge] && prime[merge]) 
						q.push(make_pair(merge,cur_cnt+1));				
			}
		}
	}

		if(ans==-1) printf("Impossible\n");
		else printf("%d\n",ans);
	}
	return 0;
}