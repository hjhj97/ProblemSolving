#include<stdio.h>
#include<vector>
using namespace std;
#define SIZE 1010

int main(){
	int t;	scanf("%d",&t);

	while(t--){
		vector <int> v[SIZE];
		int n;	scanf("%d",&n);

		for(int i=1 ; i<=n ; i++){
			int to;	scanf("%d",&to);
			v[i].push_back(to);
		}
	
		bool visited[SIZE]={false};
		int cnt=0;
		for(int i=1 ; i<=n ; i++){
			if(!visited[i]){
				int start=i,node=start;
				while(1){
					visited[node]=true;
					if(!v[node].size()) break;
					int next=v[node][0];

					if(next==start) {
						cnt++;
						break;
					}
					node=next;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
