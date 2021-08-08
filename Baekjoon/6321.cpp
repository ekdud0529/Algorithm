#include <bits/stdc++.h>
using namespace std;

char n[51];

int main(int argc, char *argv[]) {
	int a, i, j;
	scanf("%d", &a);
	for(i=0;i<a;i++){
		scanf("%s", n);
		printf("String #%d\n", i+1);
		for(j=0;j<51;j++){
			if(n[j]=='Z'){
				printf("A");	
			}
			else{
				if(n[j]==0){
					break;
				}
				printf("%c", n[j]+1);
				}		
			}
		printf("\n\n");
	}
	return 0;
}
