#include <bits/stdc++.h>
using namespace std;


int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	for(int i=1; i<n; i++){
		for(int k=i; k<n; k++) printf(" ");
		printf("*");
		for(int j=0; j<i*2-3; j++) printf(" ");
		if(i>1) printf("*");
		printf("\n");
	}
	if(n>1) for(int i=0; i<2*n-1; i++) printf("*");
	return 0;
}
