#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int a, i, j, k;
	scanf("%d", &a);
	for(i=0;i<2*a-1;i++){
		if(i<a){
			for(j=0;j<i;j++){
				printf(" ");
			}
			for(k=0;k<2*(a-i)-1;k++){
				printf("*");
			}
			printf("\n");
		}
		else{
			for(j=0;j<2*a-i-2;j++){
				printf(" ");
			}
			for(k=0;k<2*(i-a+2)-1;k++){
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}
