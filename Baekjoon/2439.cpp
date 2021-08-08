#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int a, i, j, k;
	scanf("%d", &a);
	
	for(i=0;i<a;i++){
		
		for(k=1;k+i!=a;k++){
		printf(" ");
			}
		
		for(j=0;j<=i;j++){
		printf("*");
		}
		
		printf("\n");
	}
	return 0;
}
