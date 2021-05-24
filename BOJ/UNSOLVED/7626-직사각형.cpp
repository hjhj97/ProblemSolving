#include<stdio.h>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
#define SIZE 200009
typedef pair<int,int> Cord;
int n,start_i,tree_size;
int tree[SIZE*8];
vector<Cord> v;
set<int> s;
map<int,int> mp;
Cord cord[SIZE*2];
int tree[SIZE*8];
int main(){
	scanf("%d",&n);

	for(int i=0 ; i<n ; i++){
		int x1,x2,y1,y2;	scanf("%d %d %d %d",&x1,&x2,&y1,&y2);
		cord[i*2]=make_pair(x1,y1);
		cord[i*2+1]=make_pair(x2,y2);

		if(!s.count(x1)){
			s.insert(x1);
			v.push_back(x1);
		}

		if(s.count(x2)){
			s.insert(x2);
			v.push_back(x2);
		}		
	}
	sort(v.begin(),v.end());

	for(int i=0 ; i<v.size() ; i++){
		mp[v[i]]=i;
	}



	return 0;
}