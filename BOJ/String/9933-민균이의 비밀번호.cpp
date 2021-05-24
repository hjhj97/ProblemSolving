#include<stdio.h>
#include<string.h>
int main(){

	int n;	scanf("%d",&n);
	char str[101][15];

	for(int i=0 ; i<n ; i++){
		scanf("%s",str[i]);
	}

	// if(n==1){
	// 	int len=strlen(str[0]);
	// 	printf("%d %c\n",len,str[0][len/2]);
	// }

	// else 
	for(int i=0 ; i<n ; i++){
		char rev_str[15];
		int len=strlen(str[i]);

		for(int j=0 ; j<len ; j++){
			rev_str[j]=str[i][len-j-1];
		}
		rev_str[len]=0;
		// printf("%s\n",rev_str);
		for(int j=i ; j<n ; j++){
			if(strcmp(str[j],rev_str)==0){
				// printf("%s\n",str[j]);
				printf("%d %c\n",strlen(str[j]),rev_str[len/2]);
				break;
			}
		}
	}



	return 0;
}