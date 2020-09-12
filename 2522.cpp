#include <bits/stdc++.h>
using namespace std;


int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		for(int j=0; j<n-i; j++) printf(" ");
		for(int k=0; k<i; k++) printf("*");
		printf("\n");
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++) printf(" ");
		for(int k=0; k<n-i; k++) printf("*");
		printf("\n");
	}
	return 0;
}
