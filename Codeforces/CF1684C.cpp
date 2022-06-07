int main(){
  int t;  scanf("%d",&t);
  while(t--){
    int n,m;  scanf("%d %d",&n,&m);
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        scanf("%d",&a[i][j]);

    vector<int> swapped;

    for(int i=0 ; i<n ; i++){
      vector<int> sorted = a[i];
      sort(sorted.begin(),sorted.end());
      for(int j=0 ; j<m ; j++){
        if(a[i][j] != sorted[j]){
          swapped.push_back(j);
        }
      }
      if(swapped.size() > 0) break;
    }

    int imp = 0;
    if(swapped.size() == 0){
      imp = -1;
    } else if(swapped.size() > 2){
      imp = 1;
    } else {
      for(int i=0 ; i<n ; i++){
        swap(a[i][swapped[0]],a[i][swapped[1]]);
        for(int j=0 ; j<m-1 ; j++){
          if(a[i][j] > a[i][j+1]){
            imp = 1;
            break;
          }
        }
      }
    }

    if(imp == 1){
      printf("-1\n");
    } else if(imp == -1){
      printf("1 1\n");
    } else{
      printf("%d %d\n",swapped[0]+1,swapped[1]+1);
    } 
  }
}
