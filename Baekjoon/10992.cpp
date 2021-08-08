#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n-1; i++){
		for(int k=i; k<n-1; k++) printf(" ");
		printf("*");
		for(int j=0; j<(i+1)*2-3; j++) printf(" ");
		if(i>0) printf("*");
		printf("\n");
	}
	for(int i=0; i<2*n-1; i++) printf("*");
	return 0;
}
