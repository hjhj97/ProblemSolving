int main(){
  int t;  scanf("%d",&t);
  while(t--){
    int n,m;  scanf("%d %d",&n,&m);
    pii swapped={-1,-1};
    int imp = 0;

    vector<int> tmp(m+10),sorted(m+10);
    for(int i=0 ; i<n && !imp; i++){
      for(int j=0 ; j<m  ; j++){
      }

      if(swapped.first != -1){
       int c1 = swapped.first, c2 = swapped.second;
       // printf("%d %d\n",c1,c2);
       assert(c1>=0 && c2>=0 && c1<m && c2<m);
       swap(tmp[c1],tmp[c2]);
       for(int j=0 ; j<m-1 ; j++){
        if(tmp[j] > tmp[j+1]){
          imp = 1;
          break;
        }
       }
     } else {
        for(int j=0 ; j<m ; j++){
          sorted[j] = tmp[j];
        }
        sort(sorted.begin(), sorted.begin()+m);
        int diff = 0;
        pii cur = {-1,-1};
        for(int j=0 ; j<m ; j++){
          if(sorted[j] != tmp[j]){
            diff++;
            if(cur.first == -1) cur.first = j;
            else cur.second = j;
          }
          if(diff > 2) {
            imp = 1;
            break;
          }
        }
        
        if(diff == 2) {
          if(swapped.first == -1) {
            swapped = cur;
          } else if(swapped != cur){
            imp = 1;
          }
        }
      }
    }

    if(imp){
      printf("-1\n");
    }
    else{
      int c1 = max(1,swapped.first+1), c2 = max(1,swapped.second+1);
      printf("%d %d\n",c1,c2);
    } 
    // else{
    //   printf("1 1\n");
    // }
  }
}
/*
*/
