//lower bound search
#include<stdio.h>
#define SIZE 100010
int n, S;
int sum[SIZE];
int main() {
    scanf("%d %d", &n, &S);

    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        int num;    scanf("%d", &num);
        sum[i] = sum[i - 1] + num;
    }

    if(sum[n]<S) {
        printf("0\n");
        return 0;
    }
    int l=0,r=n;

  //lower bound search
    while(l+1<r){
        int mid = (r + l) / 2;
        bool possible = false;

        for (int j = mid; j <= n ; j++) {
            int cur_sum = sum[j] - sum[j-mid];
            if (cur_sum >= S) {
                possible = true;
                break;
            }
        }
        if (possible) 
            r=mid;
        else l=mid;
    }
    printf("%d\n", r);
    return 0;
}
