#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int a, i, j, k;
	scanf("%d", &a);
	for(i=0;i<2*a-1;i++){
		if(i<a){
			for(j=1;j+i!=a;j++){
				printf(" ");
			}
			for(k=0;k<2*(i+1)-1;k++){
				printf("*");
			}
			printf("\n");
		}
		else {
			for(j=0;j<i-(a-1);j++){
				printf(" ");
			}
			for(k=2;k<2*(2*a-i)-1;k++){
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}
